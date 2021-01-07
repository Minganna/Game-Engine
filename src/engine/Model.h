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

		void onLoad(std::string fileLoc);
		void readFile(std::string fileLocation);




		~Model();

	private:
		std::shared_ptr<rend::Mesh> shape;
		std::string fileLocation;
	};
}