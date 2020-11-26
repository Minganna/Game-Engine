#include <engine/myengine.h>
#include "Player.h"


#include <iostream>

using namespace myengine;



int main()
{

	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();
	std::string shaderpath, modelpath, texturepath, texturepath2;
	shaderpath = "resources/Shaders/vertfrag.shader";
	modelpath = "resources/Models/curuthers.obj";
	texturepath = "resources/Textures/curuthers_diffuse.png";
	texturepath2 = "resources/Textures/brick.png";
	pe->getComponent<Transform>()->setPosition(vec3(0.0f,0.0f,-10.0f));
	std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>(shaderpath,texturepath,modelpath);

	std::shared_ptr<Entity> pe2 = core->addEntity();
	pe2->getComponent<Transform>()->setPosition(vec3(-1.0f, 1.0f, -10.0f));
	pe2->getComponent<Transform>()->setScale(vec3(2.0f, 2.0f, 2.0f));
	std::shared_ptr<Player> player=pe2->addComponent<Player>();
	pe2->addComponent<MeshRenderer>()->setTexture(texturepath2);
	
	
	std::shared_ptr<Renderer> pc2 = pe2->addComponent<Renderer>(shaderpath, texturepath2, modelpath);

	core->start();

	return 0;
}