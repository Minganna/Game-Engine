#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>
#include <rend/rend.h>



namespace myengine
{

	struct Renderer;
	/// <summary>
	/// the texture of a 3d object
	/// </summary>
	struct Texture: public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:
		
		/// <summary>
		/// first function called on texture added
		/// </summary>
		/// <param name="fileLoc"></param>
		void onLoad(std::string fileLoc);

		/// <summary>
		/// load and link the the texture
		/// </summary>
		/// <returns></returns>
		bool loadtextureA();


		~Texture();

	private:
		/// <summary>
		/// pointer to rend::texture
		/// </summary>
		std::shared_ptr<rend::Texture> texture;
		int width, height, bitDepth;
		std::string fileLocation;
	};
}
