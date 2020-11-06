#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Exception.h"

#include <iostream>

namespace myengine
{

void Renderer::onInitialize()
{
  std::cout << "Initializing" << std::endl;

  const char* src =
    "\n#ifdef VERTEX\n                       " \
    "attribute vec3 a_Position;              " \
	"attribute vec2 a_TexCoord;              " \
	"                                        " \
    "uniform mat4 u_Model;                   " \
	"uniform mat4 u_Projection;              " \
	"                                        " \
	"varying vec2 ex_TexCoord;               " \
    "void main()                             " \
    "{                                       " \
    "  gl_Position = u_Projection * u_Model * vec4(a_Position, 1); " \
	"  ex_TexCoord = a_TexCoord;                                     " \
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

  shader = getCore()->context->createShader();
  shader->parse(src);

  shape = getCore()->context->createBuffer();
  shape->add(rend::vec3(0, 0.5f,0.0f));
  shape->add(rend::vec3(-0.5f, -0.5f,0.0f));
  shape->add(rend::vec3(0.5f, -0.5f,0.0f));
}

void Renderer::onRender()
{
  shader->setAttribute("a_Position", shape);
  shader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
  shader->setUniform("u_Projection", getCore()->getPerspective());
  shader->render();
}

}