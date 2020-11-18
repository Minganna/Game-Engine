#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "Exception.h"



namespace myengine
{

	struct Component;
	struct Core;

	struct Entity
	{
		friend struct ::myengine::Core;

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize();

			return rtn;
		}

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

		void tick();
		void render();

		void destroy();

		std::shared_ptr<Core> getCore();

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		bool destroyed;

	};

}