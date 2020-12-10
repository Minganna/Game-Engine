#include "Player.h"
#include "engine/myEngine.h"


namespace myengine
{
    void Player::onInitialize(std::shared_ptr<Entity> cam)
    {
        playerCamera = cam;
        keys[0] = 'w'; 
        keys[1] = 's';
        keys[2] = 'a';
        keys[3] = 'd';

    }
    void Player::onInitialize(std::shared_ptr<Entity> cam, char up, char down,char left,char right)
    {
        playerCamera = cam;
        keys[0] = up;
        keys[1] = down;
        keys[2] = left;
        keys[3] = right;
    }
    void Player::onTick()
	{
        vec3 p1transform = this->getTransform()->getPosition();
        p1transform.z =p1transform.z+20;
        playerCamera->getTransform()->setPosition(p1transform);
            if (getCore()->getKeyboard()->getKey(keys[0]))
            {
                getTransform()->translate(0, 0, 0.01f);
            }
            else if (getCore()->getKeyboard()->getKey(keys[1]))
            {
                getTransform()->translate(0, 0, -0.01f);
            }

            if (getCore()->getKeyboard()->getKey(keys[2]))
            {
                getTransform()->rotate(0, 0.1f, 0);
            }
            else if (getCore()->getKeyboard()->getKey(keys[3]))
            {
                getTransform()->rotate(0, -0.1f, 0);
            }
        
		
	}
}