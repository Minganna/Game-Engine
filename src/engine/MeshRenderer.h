#include "Component.h"
#include <string>
#include <memory>






namespace myengine
{

	struct Core;
	struct Texture;

	/// <summary>
	/// this struct was designed to handle all the resource, due to time related issue it was never completed
	/// </summary>
	struct MeshRenderer : public Component
	{
		void onRender();

		void setTexture(std::string path);
		void setTexture(std::shared_ptr<Texture>  texture);



	private:
		
		std::shared_ptr<Texture> tex;

	};
}