#pragma once
#include "Resource.h"
#include <string>
#include <rend/rend.h>
#include <GL/glew.h>



namespace myengine
{

	struct Renderer;
	struct Model : public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:

		void OnLoad(std::string fileLoc);
		void ReadFile(std::string fileLocation);




		~Model();

	private:
		std::shared_ptr<rend::Mesh> shape;
		std::string fileLocation;
	};
}