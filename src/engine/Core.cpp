#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "ResourceManager.h"
#include "Keyboard.h"
#include "Camera.h"



#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif  


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


namespace myengine
{
	std::shared_ptr<Core> core;

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->setWidth(WINDOW_WIDTH);
		rtn->setHeight(WINDOW_HEIGHT);
		rtn->window = SDL_CreateWindow("myengine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->getWidth(), rtn->getHeight(),
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!rtn->window)
		{
			throw Exception("Failed to create window");
		}

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw Exception("Failed to create OpenGL context");
		}

		/*initialize Audio
		rtn->device = alcOpenDevice(NULL);
		if (!rtn->device)
		{
			throw Exception("Failed to open default device");
		}
		rtn->Audiocontext = alcCreateContext(rtn->device, NULL);
		if (!rtn->context)
		{
			alcCloseDevice(rtn->device);
			throw Exception("Failed to create context");
		}
		if (!alcMakeContextCurrent(rtn->Audiocontext))
		{
			alcDestroyContext(rtn->Audiocontext);
			alcCloseDevice(rtn->device);
			throw Exception("Failed to make context current");
		}
		end of Audio initialization*/

		rtn->context = rend::Context::initialize();
		rtn->keyboard = std::make_shared<Keyboard>();

		rtn->self = rtn;
		rtn->assets = std::make_shared<ResourceManager>();
		rtn->assets->core = rtn;
		core = rtn;
		rtn->assets->self = rtn->assets;

		return rtn;
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->core = self;
		rtn->self = rtn;
		rtn->destroyed = false;

		entities.push_back(rtn);
		rtn->addComponent<Transform>();
		return rtn;
	}

	std::shared_ptr<ResourceManager> Core::GetResource()
	{
		return assets;
	}

	void Core::loop()
	{

		for (size_t ei = 0; ei < core->entities.size(); ei++)
		{
			try
			{
				core->entities.at(ei)->tick();
			}
			catch (const std::exception&)
			{
				core->entities.at(ei)->destroy();
			}
			
		}
		for (size_t ei = 0; ei < core->entities.size(); ei++)
		{
			if (core->entities.at(ei)->destroyed)
			{
				core->entities.erase(core->entities.begin() + ei);
				ei--;
			}
		}

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(400, 0, 400, 600);

		for (size_t ci = 0; ci < core->cameras.size(); ci++)
		{
			core->currentCamera = core->cameras.at(ci);

			glClear(GL_DEPTH_BUFFER_BIT);
			for (size_t ei = 0; ei < core->entities.size(); ei++)
			{
				core->entities.at(ei)->render();

			}
			glViewport(0, 0, 400, 600);
		}

		

		SDL_GL_SwapWindow(core->window);
		
	}

	glm::mat4 Core::getPerspective()
	{
		glm::mat4 perspectiveView(1.0f);
		perspectiveView = glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 100.0f);
		return perspectiveView;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return currentCamera.lock();
	}


	void Core::start()
	{	
		#ifdef EMSCRIPTEN
			emscripten_set_main_loop(Core::loop, 0, 1);
		#else
		bool running = true;
		SDL_Event e = { 0 };

		while (running)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					running = false;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					keyboard->keys.push_back(e.key.keysym.sym);
				}
				else if (e.type == SDL_KEYUP)
				{
					for (std::vector<int>::iterator it = keyboard->keys.begin();
						it != keyboard->keys.end();)
					{
						if (*it == e.key.keysym.sym) it = keyboard->keys.erase(it);
						else it++;
					}
				}
			}
			

			loop();
		}
		#endif

	}

}