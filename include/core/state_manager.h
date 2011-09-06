
#ifndef CORE_STATE_MANAGER_H
#define CORE_STATE_MANAGER_H

#include "base/state.h"

#include <list>

<<<<<<< HEAD
=======
#include <boost/any.hpp>
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a
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
<<<<<<< HEAD
		PAUSE,
		OPTIONS,
=======
		COUNT,
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a
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
<<<<<<< HEAD
		void Transition();

		std::list<Base::State*> *states;
=======

		std::list<boost::shared_ptr<Base::State>> *states;
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a

		Base::State *current_state;
		States::StateList current_type;

		Core::Window &window;
	};
}

#endif // CORE_STATE_MANAGER_H
