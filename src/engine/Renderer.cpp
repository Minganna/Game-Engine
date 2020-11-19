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

  const char* src = 
    "\n#ifdef VERTEX\n                       " \
    "attribute vec3 a_Position;              " \
	"attribute vec2 a_TexCoord;              " \
	"attribute vec3 a_Normal;              " \
	"                                        " \
    "uniform mat4 u_Model;                   " \
	"uniform mat4 u_Projection;              " \
	"                                        " \
	"varying vec2 ex_TexCoord;               " \
    "void main()                             " \
    "{                                       " \
    "  gl_Position = u_Projection * u_Model * vec4(a_Position, 1); " \
	"  ex_TexCoord = a_TexCoord;                                     " \
	"                                        " \
	"  if(a_Normal.x==9) gl_Position.x=7;    " \
    "}                                       " \
    "                                        " \
    "\n#endif\n                              " \
    "\n#ifdef FRAGMENT\n                     " \
    "                                        " \
	"uniform sampler2D in_Texture;           " \
	" varying vec2 ex_TexCoord;              " \
	"                                        " \
    "void main()                             " \
    "{                                       " \
	"  vec4 tex = texture2D(in_Texture,ex_TexCoord); " \
    "  gl_FragColor = tex;                   " \
    "}                                       " \
    "                                        " \
    "\n#endif\n                              ";

  //src = shaderfile->shaderID;
  //printf(shaderfile->shaderID);

  shader = getCore()->context->createShader();
  shader->parse(src);


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