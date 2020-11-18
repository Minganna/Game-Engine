#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>
#include <rend/rend.h>



namespace myengine
{

	struct Renderer;
	struct Texture: public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:
		
		void OnLoad(std::string fileLoc);


		bool LoadtextureA();


		~Texture();

	private:
		//GLuint textureID;
		std::shared_ptr<rend::Texture> texture;
		int width, height, bitDepth;

		std::string fileLocation;
	};
}
