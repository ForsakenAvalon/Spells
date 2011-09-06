
#ifndef CORE_STATE_MANAGER_H
#define CORE_STATE_MANAGER_H

#include "core/window.h"
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

#endif // CORE_STATE_MANAGER_H