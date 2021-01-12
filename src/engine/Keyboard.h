#include <vector>

#ifdef USE_SDL
#define KEY_A 'a'
#else 
#define KEY_A 223
#endif

namespace myengine
{

	struct Core;
	/// <summary>
	/// struct used to recognize the key pressed
	/// </summary>
	struct Keyboard
	{
		/// <summary>
		/// getter of the key pressed
		/// </summary>
		/// <param name="key" the key pressed></param>
		/// <returns></returns>
		bool getKey(int key);

	private:
		friend struct myengine::Core;
		/// <summary>
		/// collection of keyboard keys
		/// </summary>
		std::vector<int> keys;

	};

}