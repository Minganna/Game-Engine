#include "SoundSource.h"
#include "Sound.h"
#include "Entity.h"


namespace myengine
{

	void SoundSource::onInitialize(std::shared_ptr<Sound> sound)
	{
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, sound->id);
		alSourcePlay(sid);
	}
	void SoundSource::onTick()
	{
		ALint state = 0;
		alGetSourcei(sid, AL_SOURCE_STATE, &state);
		if (state == AL_STOPPED)
		{
			onDestroy();
		}
	}
	void SoundSource::onDestroy()
	{
		getEntity()->destroy();
		alDeleteSources(1, &sid);
	}

}