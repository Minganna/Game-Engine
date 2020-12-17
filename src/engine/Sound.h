#pragma once
#include "Resource.h"
#include <string>
#include <GL/glew.h>
#include <AL/al.h>
#include <memory>
#include <vector>




namespace myengine
{
	struct SoundSource;
	struct Sound : public Resource
	{
		friend struct ::myengine::Resource;
		friend struct ::myengine::SoundSource;
	public:

		void OnLoad(const std::string& path);


		void loadOgg(const std::string& fileName,
			std::vector<char>& buffer, ALenum& format, ALsizei& freq);


		~Sound();

	private:
		ALuint id;

	};
}
