#include "Component.h"
#include <string>
#include <memory>
#include <AL/al.h>


namespace myengine
{

	struct Core;
	struct Sound;
	/// <summary>
	/// struct used to link the sound source to a entity
	/// </summary>
	struct SoundSource : public Component
	{
		/// <summary>
		/// first function called on component added to a entity
		/// </summary>
		/// <param name="sound"></param>
		/// <param name="newVolume"></param>
		void onInitialize(std::shared_ptr<Sound> sound,float newVolume);
		/// <summary>
		/// called every tick
		/// </summary>
		void onTick();
		/// <summary>
		/// called when the sound file end
		/// </summary>
		void onDestroy();



	private:

		ALuint sid;
	};
}