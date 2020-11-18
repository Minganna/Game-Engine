#pragma once
#include "Component.h"
#include <vector>
#include <memory>
#include <glm/glm.hpp>



namespace myengine
{
	
	struct Core;


	struct Transform : public Component	
	{

		glm::mat4 getModel();
		void onInitialize();
		void setPosition(glm::vec3 position);
		void RotateX(float rot);
		void RotateY(float rot);
		void RotateZ(float rot);
		void setScale(glm::vec3 scale);
		//Transform(glm::vec3 pos, glm::vec3 rot,float angle, glm::vec3 scale);


	private:
		glm::mat4 model;
		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;
		float Angle;

	};
}