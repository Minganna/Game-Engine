#pragma once
#include<string>
#include<memory>

namespace myengine
{
	struct ResourceManager;
	struct Core;
	struct Resource
	{
		friend struct ::myengine::ResourceManager;
	public:

		virtual void OnLoad(std::string path);
		std::shared_ptr<Core> GetCore();
		std::shared_ptr<ResourceManager> GetManager();

	protected:
		std::string path;
		std::weak_ptr<ResourceManager> manager;
	};

}