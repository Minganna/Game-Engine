#include <SDL2/SDL.h>
#include <rend/rend.h>


#include <memory>
#include <vector>

namespace myengine
{
	struct Renderer;
	struct Entity;
	struct ResourceManager;
	struct Keyboard;
	struct Texture;

	struct Core
	{
		friend struct myengine::Renderer;
		friend struct myengine::Texture;

		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<ResourceManager> GetResource();
		std::shared_ptr<Keyboard> getKeyboard();

		void start();

		static void loop();

		int getWidth() { return width; };
		int getHeight() { return height; };

		//Screen
		void setWidth(int newWidth) { width = newWidth; };
		void setHeight(int newHeight) { height = newHeight; };
		glm::mat4 getPerspective();

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<ResourceManager> assets;
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Keyboard> keyboard;
		int width;
		int height;
	};

}