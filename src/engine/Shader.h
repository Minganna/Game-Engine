#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>



namespace myengine
{

	struct Renderer;
	/// <summary>
	/// shader resource struct
	/// </summary>
	struct Shader : public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:
		/// <summary>
		/// first function called when the resource is added
		/// </summary>
		/// <param name="fileLoc"></param>
		void onLoad(std::string fileLoc);
		/// <summary>
		/// function used to read the shader from the file
		/// </summary>
		/// <param name="fileLocation"></param>
		/// <returns></returns>
		std::string readFile(const char* fileLocation);

		


		~Shader();

	private:
		/// <summary>
		/// the content of the shader file
		/// </summary>
		std::string shaderContent;
		/// <summary>
		/// the location of the file
		/// </summary>
		std::string fileLocation;
	};
}
