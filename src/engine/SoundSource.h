#include "Component.h"
#include <string>
#include <memory>
#include <AL/al.h>


namespace myengine
{

	struct Core;
	struct Sound;

	struct SoundSource : public Component
	{
		void onInitialize(std::shared_ptr<Sound> sound);
		void onTick();
		void onDestroy();



	private:

		ALuint sid;
	};
}