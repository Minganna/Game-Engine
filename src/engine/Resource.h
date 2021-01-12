#pragma once
#include<string>
#include<memory>

namespace myengine
{
	struct ResourceManager;
	struct Core;
	/// <summary>
	/// base class for all the resources in the engine such as model, shaders etc
	/// </summary>
	struct Resource
	{
		friend struct ::myengine::ResourceManager;
	public:
		/// <summary>
		/// base function for the first function called on resource loaded
		/// </summary>
		/// <param name="path"></param>
		virtual void onLoad(std::string path);
		/// <summary>
		/// getter of the core struct 
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Core> getCore();
		/// <summary>
		/// getter of the resource manager pointer
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<ResourceManager> getManager();

	protected:
		/// <summary>
		/// the path to the folder where the resource is 
		/// </summary>
		std::string path;
		/// <summary>
		/// pointer to the resource manager
		/// </summary>
		std::weak_ptr<ResourceManager> manager;
	};

}