
#include <list>
#include<string>
#include <memory>

namespace myengine
{

	struct Core;
	struct Resource;
	/// <summary>
	/// this struct track every resources added and avoid duplication
	/// </summary>
	struct ResourceManager
	{
	public:
		friend struct ::myengine::Core;
		
		/// <summary>
		/// used to load the resource
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="path"></param>
		/// <returns></returns>
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
		/// <summary>
		/// getter of the core struct
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Core> getCore();

	private:
		/// <summary>
		/// pointer to self
		/// </summary>
		std::weak_ptr<ResourceManager> self;
		/// <summary>
		/// pointer to core
		/// </summary>
		std::weak_ptr<Core> core;
		/// <summary>
		/// list of all the resource loaded in the scene
		/// </summary>
		std::list<std::shared_ptr<Resource>> resources;
	};

}