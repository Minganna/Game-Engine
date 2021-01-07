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

		virtual void onLoad(std::string path);
		std::shared_ptr<Core> getCore();
		std::shared_ptr<ResourceManager> getManager();

	protected:
		std::string path;
		std::weak_ptr<ResourceManager> manager;
	};

}