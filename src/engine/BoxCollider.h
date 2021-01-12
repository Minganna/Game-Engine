#include "Component.h"
#include "glm/glm.hpp"


namespace myengine
{

	struct CollisionManager;
	///
	///  \brief struct that deals with box colliders
	/// this struct utilize the AABB method to check if two objects are colliding, if they collide, it will push them away
	struct BoxCollider : public Component
	{
		/// first function called on creation
		void onInitialize();
		/// called every update
		void onTick();
		

		//void onDestroy();
	private:
		/// \brief this function use the AABB collision to check if two collider are colliding, 
		/// if the two objects are colliding, the function then check the more convenient direction where to push the colliding object away
		///   \param size the other box collider size
		///    \param position the other box Collider position
		glm::vec3 getCollisionResponse(glm::vec3 size, glm::vec3 position);

		///the size of the box collider
		glm::vec3 boxSize;
		///the center of the box collider
		glm::vec3 originPoint;
		/// \brief the last known position of the entity
		/// this vector was meant to be implemented in case the entity was colliding with more than one collider. 
		/// due to time related issues, the function was not implemented
		glm::vec3 lastposition;
		/// pointer to the collisionManager struct
		std::weak_ptr<CollisionManager> collisionManager;
		
	};

}