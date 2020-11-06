#pragma once
#include "Resource.h"
#include <string>
#include <GL\glew.h>



namespace myengine
{

	class Texture: public Resource
	{
		friend struct ::myengine::Resource;
	public:
		
		void OnLoad(std::string fileLoc);

		bool LoadTexture();
		bool LoadtextureA();

		void UseTexture();
		void ClearTexture();

		~Texture();

	private:
		GLuint textureID;
		int width, height, bitDepth;

		std::string fileLocation;
	};
}
