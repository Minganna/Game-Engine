#pragma once
#include<string>
#include<memory>

namespace myengine
{
	struct ResourceManager;
	struct Resource
	{
		friend struct ::myengine::ResourceManager;
	public:

		virtual void OnLoad(std::string path);

	protected:
		std::string path;
		std::weak_ptr<ResourceManager> manager;
	};

}