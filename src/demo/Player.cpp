#include "Player.h"
#include "engine/myEngine.h"


namespace myengine
{
	void Player::onTick()
	{
            if (getCore()->getKeyboard()->getKey('w'))
            {
                getTransform()->translate(0, 0, 0.01f);
            }
            else if (getCore()->getKeyboard()->getKey('s'))
            {
                getTransform()->translate(0, 0, -0.01f);
            }

            if (getCore()->getKeyboard()->getKey('a'))
            {
                getTransform()->rotate(0, 0.1f, 0);
            }
            else if (getCore()->getKeyboard()->getKey('d'))
            {
                getTransform()->rotate(0, -0.1f, 0);
            }
        
		
	}
}