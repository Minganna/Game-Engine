#include "Entity.h"
#include "Component.h"

namespace myengine
{

	Entity::~Entity() { }

	void Entity::tick()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			//components.at(ci)->tick();
		}
	}

}