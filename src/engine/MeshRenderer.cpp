#include "MeshRenderer.h"
#include "Texture.h"
#include "Core.h"
#include "ResourceManager.h"


namespace myengine
{
	void MeshRenderer::onRender()
		{
	
		}
	void MeshRenderer::setTexture(std::string path)
	{
		tex=getCore()->GetResource()->LoadResource<Texture>(path);
	}
	void MeshRenderer::setTexture(std::shared_ptr<Texture> texture)
	{
		tex = texture;
	}
}

