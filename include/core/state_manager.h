
#ifndef CORE_STATE_MANAGER_H
#define CORE_STATE_MANAGER_H

#include "base/state.h"

#include <list>

#include <boost/shared_ptr.hpp>
#include <SFML/Window/Event.hpp>

namespace Core
{
	class Window;
}

namespace States
{
	enum StateList
	{
		MENU = 0,
		GAME,
		PAUSE,
		OPTIONS,
	};
}

namespace Core
{
	class StateManager
	{
	public:
		StateManager( Core::Window &window );
		~StateManager();
		
		bool Update();
		bool Events( sf::Event &objEvent );

		bool SetState( const States::StateList name );

	private:
		bool CheckCurrent();
		void Transition();

		std::list<Base::State*> *states;

		Base::State *current_state;
		States::StateList current_type;

		Core::Window &window;
	};
}

#endif // CORE_STATE_MANAGER_H
