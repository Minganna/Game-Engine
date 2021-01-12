#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "Exception.h"



namespace myengine
{

	struct Component;
	struct Core;
	struct Exception;
	struct Transform;
	/// <summary>
	/// base class for every game object in the scene
	/// </summary>
	struct Entity
	{
		friend struct ::myengine::Core;
		/// <summary>
		/// used to add a component to an entity
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize();

			return rtn;
		}

		/// <summary>
		/// used to add a component to the entity and pass a n of parameter in the onInitialize function
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args"></param>
		/// <returns></returns>
		template <typename T, typename ... Args>
		std::shared_ptr<T> addComponent(Args&& ... args)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInitialize(std::forward<Args>(args)...);
			return rtn;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t ci = 0; ci < components.size(); ci++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(ci));
				if (rtn)
				{
					return rtn;
				}
			}
			throw Exception("Cannot find requested component type");
		}


		/// <summary>
		/// this function is called every tick
		/// </summary>
		void tick();
		/// <summary>
		///  this function is called on rendering
		/// </summary>
		void render();
		/// <summary>
		/// this function is called when the component is destroyed
		/// </summary>
		void destroy();
		/// <summary>
		/// getter of the core pointer
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Core> getCore();
		/// <summary>
		/// getter of the associated transform component
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Transform> getTransform();

	private:
		/// <summary>
		/// collection of components associated to the entity
		/// </summary>
		std::vector<std::shared_ptr<Component>> components;
		/// <summary>
		/// pointer to core
		/// </summary>
		std::weak_ptr<Core> core;
		/// <summary>
		/// pointer to self
		/// </summary>
		std::weak_ptr<Entity> self;
		/// <summary>
		/// this bool detect if the entity need to be destroyed
		/// </summary>
		bool destroyed;

	};

}