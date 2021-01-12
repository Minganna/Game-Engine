#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	/// struct that deal with the camera
	struct Camera : public Component
	{
		///first function called when camera object is created
		void onInitialize();
		//void onDestroy();
		///getter of the view
		rend::mat4 getView();
	};

}
