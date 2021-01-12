#include<memory>
#include <list>

namespace myengine
{
	struct BoxCollider;
	///this class is used to track every collider added in the scene
	struct CollisionManager
	{
		///add the newly created collider to the list 
		void setCollider(std::weak_ptr<BoxCollider> box) { boxColliders.push_back(box); };
		///getter the collider list
		std::list<std::weak_ptr<BoxCollider>> getColliderList() { return boxColliders; };
		

	private:
		/// <summary>
		/// list of box collider added in the scene
		/// </summary>
		std::list<std::weak_ptr<BoxCollider>> boxColliders;
	};
}