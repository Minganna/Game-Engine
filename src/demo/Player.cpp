#include "Player.h"
#include "engine/myEngine.h"


namespace myengine
{
	void Player::onTick()
	{
		getEntity()->getComponent<Transform>()->RotateY(45.0f);
	}
}