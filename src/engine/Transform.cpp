#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace myengine
{



glm::mat4 Transform::getModel()
{
	model=glm::mat4(1.0f);
	model = glm::translate(model, Position);
	model = glm::rotate(model,Angle,Rotation);
	model = glm::scale(model, Scale);
	return model;
}

void Transform::onInitialize()
{
	Position = glm::vec3(0.0f, 0.0f, 0.0f);
	Rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	Angle = glm::radians(0.0f);
}

void Transform::setPosition(glm::vec3 position)
{
	Position = position;
}

void Transform::setScale(glm::vec3 scale)
{
	Scale = scale;
}

void Transform::RotateY(float rot)
{
	Angle = glm::radians(rot);
	model = glm::rotate(model, Angle, Rotation);
}




}