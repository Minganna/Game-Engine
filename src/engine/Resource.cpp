#include "Resource.h"
#include "ResourceManager.h"

namespace myengine
{
	void Resource::onLoad(std::string path)
	{
	}
	std::shared_ptr<Core> Resource::getCore()
	{
		return getManager()->getCore();
	}
	std::shared_ptr<ResourceManager> Resource::getManager()
	{
		return manager.lock();
	}
}