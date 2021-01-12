#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <rend/rend.h>
#include <memory>
#include <vector>

/// <summary>
/// namespace that include all the code used by the engine and should not be used by the user
/// </summary>
namespace myengine
{
	//forward declared structs used in core
	struct Renderer;
	struct Entity;
	struct ResourceManager;
	struct Keyboard;
	struct Texture;
	struct Shaders;
	struct Model;
	struct Camera;
	struct CollisionManager;
	/// main struct that manage and keep track of everything in the game engine
	struct Core
	{


		static std::shared_ptr<Core> initialize();

		/// add a new entity to the scene.
		std::shared_ptr<Entity> addEntity(); 
		/// getter of the resourceManager struct pointer.
		std::shared_ptr<ResourceManager> getResource();
		/// getter of the Keyboard struct pointer.
		std::shared_ptr<Keyboard> getKeyboard();
		/// getter of the Camera struct  pointer.
		std::shared_ptr<Camera> getCamera();
		/// getter of the CollisionManager struct pointer.
		std::shared_ptr<CollisionManager> getCollisionManager();

		/// start the engine
		void start();
		/// loop until the game is closed
		static void loop();

		/// getter of window width
		int getWidth() { return width; };
		/// getter of the window height
		int getHeight() { return height; };

		//Screen
		///
		/// \brief setter of the screen width
		///  
		///  \param newWidth new width to assign
		///

		void setWidth(int newWidth) { width = newWidth; };
		///
		/// \brief setter of the screen height
		///  
		///  \param newHeight new height to assign
		///

		void setHeight(int newHeight) { height = newHeight; };
		///get the perspective view
		glm::mat4 getPerspective();

	private:
		//friend structs
		friend struct myengine::Renderer;
		friend struct myengine::Texture;
		friend struct myengine::Shaders;
		friend struct myengine::Model;
		friend struct myengine::Camera;

		///collection of all the entities created in the scene
		std::vector<std::shared_ptr<Entity>> entities;
		///pointer to the resourceManager struct
		std::shared_ptr<ResourceManager> assets;

		//Camera 
		///pointer to the current camera
		std::weak_ptr<Camera> currentCamera;
		///collection of all the camera included in the scene
		std::vector<std::weak_ptr<Camera>> cameras;
		//Collision
		///pointer to the collisionManager struct 
		std::shared_ptr<CollisionManager> collisionManager;

		///pointer to the core
		std::weak_ptr<Core> self;
		///the game window
		SDL_Window* window;
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Keyboard> keyboard;
		int width;
		int height;
		ALCdevice* device;
		ALCcontext* audioContext;

	};

}