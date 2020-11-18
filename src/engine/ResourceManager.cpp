#include "ResourceManager.h"
#include "Core.h"

namespace myengine
{
	std::shared_ptr<Core> ResourceManager::GetCore()
	{
		return core.lock();
	}
}

