#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{

	void Camera::onInitialize()
	{
		std::shared_ptr<Camera> self = getEntity()->getComponent<Camera>();
		getCore()->cameras.push_back(self);
	}

	rend::mat4 Camera::getView()
	{
		return rend::inverse(getTransform()->getModel());
	}

}

