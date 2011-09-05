
#ifndef STATE_MANAGER_CORE_H
#define STATE_MANAGER_CORE_H

#include "engine/window_engine.h"
#include "utility/string.h"
#include "base/state.h"

namespace Core
{
	//! /brief Manages the possible states in the game and also transistions in between.
	class StateManager
	{
		public:
			StateManager(Window * window);
			~StateManager();

			void AddState(const char * debugName, void (*entryFunc)(), bool (*conditionFunc)());
			bool Transistion(unsigned int stateId);
		private:
			Window * objWindow;
			unsigned int totalStateCount;
			unsigned int curStateId;
	};
}

#endif // STATE_MANAGER_CORE_H