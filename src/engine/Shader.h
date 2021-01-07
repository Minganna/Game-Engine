#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>



namespace myengine
{

	struct Renderer;
	struct Shader : public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:

		void onLoad(std::string fileLoc);
		std::string readFile(const char* fileLocation);

		


		~Shader();

	private:
		std::string shaderContent;
		std::string fileLocation;
	};
}
