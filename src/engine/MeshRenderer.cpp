#include "MeshRenderer.h"
#include "Texture.h"
#include "Core.h"
#include "ResourceManager.h"


namespace myengine
{
	void MeshRenderer::onRender()
		{
		tex->UseTexture();
		}
	void MeshRenderer::setTexture(std::string path)
	{
		tex=getCore()->GetResource()->LoadResource<Texture>("resources/brick.png");
	}
	void MeshRenderer::setTexture(std::shared_ptr<Texture> texture)
	{
		tex = texture;
	}
}

