#include<memory>
#include <list>

namespace myengine
{
	struct BoxCollider;

	struct CollisionManager
	{
		void setCollider(std::weak_ptr<BoxCollider> box) { boxColliders.push_back(box); };
		std::list<std::weak_ptr<BoxCollider>> getColliderList() { return boxColliders; };
		

	private:
		std::list<std::weak_ptr<BoxCollider>> boxColliders;
	};
}