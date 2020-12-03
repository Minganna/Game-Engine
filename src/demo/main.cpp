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
	std::shared_ptr<Player> player=pe2->addComponent<Player>();
	pe2->addComponent<MeshRenderer>()->setTexture(texturepath2);
	std::shared_ptr<Renderer> pc2 = pe2->addComponent<Renderer>(shaderpath, texturepath2, modelpath);

	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();

	std::shared_ptr<Entity> c2 = core->addEntity();
	vec3 p1transform = pe->getTransform()->getPosition();
	p1transform.z = 0;
	c2->getTransform()->setPosition(p1transform);
	c2->addComponent<Camera>();

	core->start();

	return 0;
}