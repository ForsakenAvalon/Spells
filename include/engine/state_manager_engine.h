
#ifndef STATE_MANAGER_ENGINE_H
#define STATE_MANAGER_ENGINE_H

#include "engine/window_engine.h"

namespace Core
{
	class StateManager
	{
		public:
			StateManager(Window * window);
			~StateManager();

			bool Transition();
		private:
	};
}

#endif // STATE_MANAGER_ENGINE_H