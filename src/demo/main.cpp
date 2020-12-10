#include <engine/myengine.h>
#include "Player.h"


#include <iostream>

using namespace myengine;



int main()
{

	std::shared_ptr<Core> core = Core::initialize();
	std::string shaderpath, modelpath, texturepath, texturepath2;
	shaderpath = "resources/Shaders/vertfrag.shader";
	modelpath = "resources/Models/curuthers.obj";
	texturepath = "resources/Textures/curuthers_diffuse.png";
	texturepath2 = "resources/Textures/brick.png";

	std::shared_ptr<Entity> pe = core->addEntity();
	pe->getComponent<Transform>()->setPosition(vec3(0.0f,0.0f,-10.0f));
	pe->getComponent<Transform>()->rotate(0, 180.0f, 0);
	std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>(shaderpath,texturepath,modelpath);
	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	std::shared_ptr<Player> player = pe->addComponent<Player>(camera);

	std::shared_ptr<Entity> pe2 = core->addEntity();
	pe2->getComponent<Transform>()->setPosition(vec3(-10.0f, 0.0f, -10.0f));
	pe2->getComponent<Transform>()->rotate(0, 180.0f, 0);
	std::shared_ptr<Entity> c2 = core->addEntity();
	c2->addComponent<Camera>();
	std::shared_ptr<Player> player2 = pe2->addComponent<Player>(c2, 'i', 'k', 'j','l');
	std::shared_ptr<Renderer> pc2 = pe2->addComponent<Renderer>(shaderpath, texturepath2, modelpath);
	




	core->start();

	return 0;
}