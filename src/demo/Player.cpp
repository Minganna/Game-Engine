#include "Player.h"
#include "engine/myEngine.h"


namespace myengine
{
	void Player::onTick()
	{
		if (getCore()->getKeyboard()->getKey('d'))
		{
			// Rotate right
			getEntity()->getComponent<Transform>()->RotateY(0.1f);
		}
		if (getCore()->getKeyboard()->getKey('a'))
		{
			// Rotate left
			getEntity()->getComponent<Transform>()->RotateY(-0.1f);
		}
		if (getCore()->getKeyboard()->getKey('w'))
		{
			// Rotate up
			getEntity()->getComponent<Transform>()->RotateX(0.1f);
		}
		if (getCore()->getKeyboard()->getKey('s'))
		{
			// Rotate down
			getEntity()->getComponent<Transform>()->RotateX(-0.1f);
		}
		
	}
}