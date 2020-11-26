#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Exception.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Shader.h"
#include "Model.h"
#include <fstream>
#include <string>

#include <iostream>

namespace myengine
{

void Renderer::onInitialize()
{
  std::cout << "Initializing" << std::endl;

  shaderfile = getCore()->GetResource()->LoadResource<Shader>("resources/Shaders/vertfrag.shader");

  shader = getCore()->context->createShader();
  shader->parse(shaderfile->shaderContent);


  shape = getCore()->GetResource()->LoadResource<Model>("resources/Models/curuthers.obj");
  texture = getCore()->GetResource()->LoadResource<Texture>("resources/Textures/curuthers_diffuse.png");
}

void Renderer::onRender()
{
  shader->setMesh(shape->shape);
  shader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
  shader->setUniform("u_Projection", getCore()->getPerspective());
  shader->setSampler("in_Texture", texture->texture);
  shader->render();
}

}