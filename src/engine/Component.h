#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{

	struct Entity;
	struct Core;
	struct Transform;
	/// <summary>
	/// this is the base struct for all the component class in the engine
	/// </summary>
	struct Component
	{
		friend struct myengine::Entity;

		/// <summary>
		/// this function is called when the component is added
		/// </summary>
		virtual void onInitialize();

		/// <summary>
		/// this function is called every tick
		/// </summary>
		void tick();
		/// <summary>
		///  this function is called every tick and can be updated depending on the component type
		/// </summary>
		virtual void onTick();

		/// <summary>
		///  this function is called on rendering
		/// </summary>
		void render();
		/// <summary>
		///  this function is called on rendering and can be updated depending on the component type
		/// </summary>
		virtual void onRender();
		/// <summary>
		/// this function is called when the component is destroyed
		/// </summary>
		virtual void onDestroy();

		/// <summary>
		/// getter of the associated entity component
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Entity> getEntity();
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
		/// pointer to the associated entity
		/// </summary>
		std::weak_ptr<Entity> entity;

	};

}

#endif