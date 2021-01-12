#pragma once
#include "Resource.h"
#include <string>
#include <rend/rend.h>
#include <GL/glew.h>



namespace myengine
{

	struct Renderer;
	/// <summary>
	/// struct used to load 3d model to the scene
	/// </summary>
	struct Model : public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::Renderer;
	public:
		/// <summary>
		/// first function called on resource loaded
		/// </summary>
		/// <param name="fileLoc"></param>
		void onLoad(std::string fileLoc);
		/// <summary>
		/// function called to read and get the model from an extrenal file
		/// </summary>
		/// <param name="fileLocation"></param>
		void readFile(std::string fileLocation);




		~Model();

	private:
		/// <summary>
		/// the model shape
		/// </summary>
		std::shared_ptr<rend::Mesh> shape;
		/// <summary>
		/// the file location
		/// </summary>
		std::string fileLocation;
	};
}