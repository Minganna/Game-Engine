#include "ResourceManager.h"
#include "Core.h"

namespace myengine
{
	std::shared_ptr<Core> ResourceManager::getCore()
	{
		return core.lock();
	}
}

