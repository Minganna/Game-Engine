
#include <list>
#include<string>
#include <memory>

namespace myengine
{

	struct Core;
	struct Resource;
	struct ResourceManager
	{
	public:
		friend struct ::myengine::Core;
		

		template <typename T>
		std::shared_ptr<T> loadResource(std::string path)
		{
			std::shared_ptr<T> rtn;
			if (!resources.empty())
			{
				for (std::list<std::shared_ptr<Resource>>::iterator it=resources.begin();it!=resources.end();++it )
				{
					rtn = std::dynamic_pointer_cast<T>(*it);
					if (rtn)
					{
						if (rtn->path==path)
						{
							return rtn;
						}
					}
				}
			}
			 rtn= std::make_shared<T>();
			rtn->manager = self;
			rtn->onLoad(path);
			resources.push_back(rtn);

			return rtn;
		}

		std::shared_ptr<Core> getCore();

	private:
		std::weak_ptr<ResourceManager> self;
		std::weak_ptr<Core> core;
		std::list<std::shared_ptr<Resource>> resources;
	};

}