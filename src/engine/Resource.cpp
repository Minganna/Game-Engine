#include "Resource.h"
#include "ResourceManager.h"

namespace myengine
{
	void Resource::OnLoad(std::string path)
	{
	}
	std::shared_ptr<Core> Resource::GetCore()
	{
		return GetManager()->GetCore();
	}
	std::shared_ptr<ResourceManager> Resource::GetManager()
	{
		return manager.lock();
	}
}