#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>
#include <AL/al.h>
#include <memory>
#include <vector>




namespace myengine
{
	struct Sound : public Resource
	{
		friend struct ::myengine::Resource;
	public:

		void onLoad(const std::string& path);


		ALuint loadOgg(const std::string& fileName,
			std::vector<char>& buffer, ALenum& format, ALsizei& freq);


		~Sound();

	private:
		ALuint id;

	};
}
