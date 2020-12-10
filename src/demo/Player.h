#pragma once
#include "engine\Component.h"
namespace myengine
{
	class Player :
		public Component
	{
	public:
		void onInitialize(std::shared_ptr<Entity> cam);
		void onInitialize(std::shared_ptr<Entity> cam,char up, char down, 
													  char left, char right);
		void onTick();

	private:
		std::shared_ptr<Entity> playerCamera;
		char keys[4];

	};


}
