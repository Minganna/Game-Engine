#include "BoxCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "CollisionManager.h"

namespace myengine
{
	void BoxCollider::onInitialize()
	{
		boxSize = glm::vec3(1.0f,1.0f,1.0f);
		originPoint= glm::vec3(0.0f, 0.0f, 0.0f);
		lastposition=getEntity()->getTransform()->getPosition();
		collisionManager = getCore()->getCollisionManager();
		collisionManager.lock()->setCollider(getEntity()->getComponent<BoxCollider>());
	}

	void BoxCollider::onTick()
	{
		std::list<std::weak_ptr<BoxCollider>> boxColliders=collisionManager.lock()->getColliderList();
		glm::vec3 currentPosition = getEntity()->getTransform()->getPosition() + originPoint;
		for (std::list<std::weak_ptr<BoxCollider>>::iterator it = boxColliders.begin(); it != boxColliders.end(); ++it)
		{
			glm::vec3 newpos= it->lock()->getCollisionResponse(boxSize, currentPosition);
			getEntity()->getTransform()->setPosition(newpos);
		}

	}

	glm::vec3 BoxCollider::getCollisionResponse(glm::vec3 size, glm::vec3 position)
	{
		glm::vec3 currentPosition = getEntity()->getTransform()->getPosition() + originPoint;
		if (currentPosition == position)
		{
			return position;
		}
		bool right,top,front;
		if (currentPosition.x>position.x)//check A right to B
		{
			right = true;
			if (currentPosition.x-boxSize.x>position.x+size.x)
			{
				return position;
			}
		}
		else //A left to B
		{
			right = false;
			if ((position.x - size.x) > (currentPosition.x + boxSize.x))
			{
				return position;
			}
		}
		if (currentPosition.y > position.y)//check A on top of B
		{
			top = true;
			if (currentPosition.y - boxSize.y > position.y + size.y)
			{
				return position;
			}
		}
		else //A under to B
		{
			top = false;
			if (position.y - size.y > currentPosition.y + boxSize.y)
			{
				return position;
			}
		}
		if (currentPosition.z > position.z)//check A on front of B
		{
			front = true;
			if (currentPosition.z - boxSize.z > position.z + size.z)
			{
				return position;
			}
		}
		else //A behind to B
		{
			front = false;
			if (position.z - size.z > currentPosition.z + boxSize.z)
			{
				return position;
			}
		}
		glm::vec3 difX(0), difY(0), difZ(0);
		if (right)
		{
			float point1 = currentPosition.x - boxSize.x;
			float point2 = position.x + size.x;
			difX.x= point2 - point1;
		}
		else
		{
			float point1 = boxSize.x+currentPosition.x;
			float point2 = position.x - size.x;
			difX.x = -(point1 - point2);
		}
		if (top)
		{
			float point1 = currentPosition.y - boxSize.y;
			float point2 = position.y + size.y;
			difY.y = point2 - point1;
		}
		else
		{
			float point1 = boxSize.y + currentPosition.y;
			float point2 = position.y-size.y;
			difY.y = -(point1 - point2);
		}
		if (front)
		{
			float point1 = currentPosition.z - boxSize.z;
			float point2 = position.z + size.z;
			difZ.z = point2 - point1;
		}
		else
		{
			float point1 = boxSize.z + currentPosition.z;
			float point2 = position.z - size.z;
			difZ.z = -(point1 - point2);
		}
		glm::vec3 mindiff(0);

		if (glm::length(difX)< glm::length(difY))
		{
			mindiff = difX;
		}
		else
		{
			mindiff = difY;
		}
		if (glm::length(difZ)< glm::length(mindiff))
		{
			mindiff = difZ;
		}
		return position - mindiff;
		
	}

}
