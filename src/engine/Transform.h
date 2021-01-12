#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	/// <summary>
	/// the 3d object position,rotation and size 
	/// </summary>
	struct Transform : public Component
	{
		/// <summary>
		/// first function called on component added
		/// </summary>
		void onInitialize();
		/// <summary>
		/// used to get the model matrix
		/// </summary>
		/// <returns></returns>
		rend::mat4 getModel();
		/// <summary>
		/// setter of the model position
		/// </summary>
		/// <param name="position"></param>
		void setPosition(rend::vec3 position);
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		rend::vec3 getPosition();
		/// <summary>
		/// used to move the model
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		void translate(float x, float y, float z);
		/// <summary>
		/// used to rotate the model
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		void rotate(float x, float y, float z);
		/// <summary>
		/// used to scale the model
		/// </summary>
		/// <param name="newscale"></param>
		void setScale(glm::vec3 newscale);

	private:
		/// <summary>
		/// the model position in space
		/// </summary>
		rend::vec3 position;
		/// <summary>
		/// the model rotation in space
		/// </summary>
		rend::vec3 rotation;
		/// <summary>
		/// the scale of the object
		/// </summary>
		rend::vec3 scale;

	};

}
