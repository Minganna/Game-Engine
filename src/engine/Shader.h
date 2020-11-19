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

		void OnLoad(std::string fileLoc);
		std::string ReadFile(const char* fileLocation);

		


		~Shader();

	private:
		const char* shaderID;
		std::string fileLocation;
	};
}
