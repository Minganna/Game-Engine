#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Exception.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"

#include <fstream>
#include <string>

#include <iostream>

namespace myengine
{

void Renderer::onInitialize(std::string shaderpath,std::string texurepath,std::string modelpath)
{
  std::cout << "Initializing" << std::endl;

  shaderfile = getCore()->getResource()->loadResource<Shader>(shaderpath);

  shader = getCore()->context->createShader();
  shader->parse(shaderfile->shaderContent);


  shape = getCore()->getResource()->loadResource<Model>(modelpath);
  texture = getCore()->getResource()->loadResource<Texture>(texurepath);
}

void Renderer::onRender()
{
  shader->setMesh(shape->shape);
  shader->setUniform("u_Projection", getCore()->getPerspective());
  shader->setUniform("u_View", getCore()->getCamera()->getView());
  shader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
  
  shader->setSampler("in_Texture", texture->texture);
  shader->render();
}

}