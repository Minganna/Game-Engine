#include "Component.h"
#include "glm/glm.hpp"


namespace myengine
{
	struct CollisionManager;
	struct BoxCollider : public Component
	{
		void onInitialize();
		void onTick();
		

		//void onDestroy();
	private:

		glm::vec3 getCollisionResponse(glm::vec3 size, glm::vec3 position);

		glm::vec3 boxSize;
		glm::vec3 originPoint;
		glm::vec3 lastposition;
		std::weak_ptr<CollisionManager> collisionManager;
		
	};

}