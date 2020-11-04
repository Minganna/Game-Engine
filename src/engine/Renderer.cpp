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
    "uniform mat4 u_Model;                   " \
	"uniform mat4 u_Projection;              " \
    "void main()                             " \
    "{                                       " \
    "  gl_Position = u_Projection * u_Model * vec4(a_Position, 1); " \
    "}                                       " \
    "                                        " \
    "\n#endif\n                              " \
    "\n#ifdef FRAGMENT\n                     " \
    "                                        " \
    "void main()                             " \
    "{                                       " \
    "  gl_FragColor = vec4(1, 0, 0, 1);      " \
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
  //shader->setUniform("u_Model", glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -10.0f)));
  shader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
  shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f),1.0f,0.01f,100.0f));
  shader->render();
}

}