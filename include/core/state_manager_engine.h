
#ifndef STATE_MANAGER_ENGINE_H
#define STATE_MANAGER_ENGINE_H

#include "engine/window_engine.h"

namespace Core
{
	//! /brief Manages the possible states in the game and also transistions in between.
	class StateManager
	{
		public:
			StateManager(Window * window);
			~StateManager();

			bool Transistion(unsigned int stateId);
		private:
			Window * window;
	};
}

#endif // STATE_MANAGER_ENGINE_H