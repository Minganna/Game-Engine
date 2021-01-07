#include <engine/myengine.h>
#include "Player.h"


#include <iostream>

using namespace myengine;



int main()
{

	std::shared_ptr<Core> core = Core::initialize();
	std::string shaderpath, modelpath, texturepath, texturepath2, soundpath,housepath, texturehouse;
	shaderpath = "resources/Shaders/vertfrag.shader";
	modelpath = "resources/Models/curuthers.obj";
	housepath = "resources/Models/re_hall_baked.obj";
	texturepath = "resources/Textures/curuthers_diffuse.png";
	texturepath2 = "resources/Textures/brick.png";
	texturehouse = "resources/Textures/re_hall_diffuse.png";
	soundpath = "resources/Sound Effect/Waterfall loop";

	std::shared_ptr<Entity> pe = core->addEntity();
	pe->getComponent<Transform>()->setPosition(vec3(0.0f,0.0f,-10.0f));
	pe->getComponent<Transform>()->rotate(0, 180.0f, 0);
	std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>(shaderpath,texturepath,modelpath);
	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	std::shared_ptr<Player> player = pe->addComponent<Player>(camera);
	std::shared_ptr<BoxCollider> collider = pe->addComponent<BoxCollider>();

	std::shared_ptr<Entity> pe2 = core->addEntity();
	pe2->getComponent<Transform>()->setPosition(vec3(-10.0f, 0.0f, -10.0f));
	pe2->getComponent<Transform>()->rotate(0, 180.0f, 0);
	std::shared_ptr<Entity> c2 = core->addEntity();
	c2->addComponent<Camera>();
	std::shared_ptr<Player> player2 = pe2->addComponent<Player>(c2, 'i', 'k', 'j','l');
	std::shared_ptr<Renderer> pc2 = pe2->addComponent<Renderer>(shaderpath, texturepath2, modelpath);
	std::shared_ptr<BoxCollider> collider2 = pe2->addComponent<BoxCollider>();

	std::shared_ptr<Entity> pe3 = core->addEntity();
	std::shared_ptr<Sound> sound = core->getResource()->loadResource<Sound>(soundpath);
	std::shared_ptr<SoundSource> ss = pe3->addComponent<SoundSource>(sound,0.1f); //the only one

	std::shared_ptr<Entity> house = core->addEntity();
	house->getComponent<Transform>()->setPosition(vec3(0.0f, 2.5f, -10.0f));
	house->getComponent<Transform>()->rotate(0, 90.0f, 0);
	glm::vec3 newscale(2.0f, 2.0f, 2.0f);
	house->getComponent<Transform>()->setScale(newscale);
	std::shared_ptr<Renderer> housepc = house->addComponent<Renderer>(shaderpath, texturehouse, housepath);
	
	


	core->start();

	return 0;
}