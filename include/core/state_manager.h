
#ifndef CORE_STATE_MANAGER_H
#define CORE_STATE_MANAGER_H

#include "base/state.h"

#include <list>

#include <SFML/Window/Event.hpp>

namespace Core
{
	class Window;
}

namespace StateType
{
	//! Contains an element for each state so that states can be easily
	//! selected throughout the program.
	enum List
	{
		MENU = 0,
		GAME,
		PAUSE,
		OPTIONS,
	};
}

namespace Core
{
	//! \brief Manages all classes inherited from Base::State, defined in
	//! the StateList enumerator
	class StateManager
	{
	public:
		//! \brief Constructor
		StateManager( Core::Window &window );

		//! \brief Deconstructor
		~StateManager();

		//! \brief Calls the current states Events function
		bool Events( sf::Event &objEvent );
		
		//! \brief Calls the current states Update function
		bool Update();

		//! \brief Changes the current state to the specified state
		bool SetState( const StateType::List name );

	private:
		//! \brief Assess whether a state has been set
		//! 
		//! \return Validity of current_state
		bool CheckCurrent();

		std::list<Base::State*> *states;	//!< Contains all states
		Base::State *current_state;			//!< Holds the current state

		Core::Window &window;				//!< Core::Window reference
	};
}

#endif // CORE_STATE_MANAGER_H
