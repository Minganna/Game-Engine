#include "Texture.h"
#include "Core.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Exception.h"

namespace myengine
{

	void Texture::onLoad(std::string fileLoc)
	{
		width = 0;
		height = 0;
		bitDepth = 0;
		fileLocation = fileLoc;
		loadtextureA();
	}

	bool Texture::loadtextureA()
	{
		unsigned char* texData = stbi_load(fileLocation.c_str(), &width, &height, &bitDepth, 4);
		if (!texData)
		{
			std::string error=("Failed to find: %s\n", fileLocation.c_str());
			throw Exception(error);
			return false;
		}

		texture = getCore()->context->createTexture();
		

		texture->setSize(width, height);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int r = y * width * 4 + x * 4;

				texture->setPixel(x, y, glm::vec4(
					texData[r] / 255.0f,
					texData[r + 1] / 255.0f,
					texData[r + 2] / 255.0f,
					texData[r + 3] / 255.0f));

			}
		}

		stbi_image_free(texData);

		return true;
	}



	Texture::~Texture()
	{
	
	}
}
