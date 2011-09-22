
#ifndef STATES_MENU_H
#define STATES_MENU_H

#include "states/state.h"

namespace Core
{
	class Window;
}

namespace States
{
	//! \brief An initial state, the game menu
	class Menu : public State
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new state with the specified enum name and Core::Window reference.
		//! 
		//! \param state	StateType of this state
		//! \param window	Core::Window reference
		Menu( const StateType::List state, Core::Window &window );

		//! \brief Deconstructor
		~Menu();

		//! \brief Handles the menu state events
		//! 
		//! \param objEvent Event from the event loop
		void Events( sf::Event &objEvent );

		//! \brief Handles the menu state updates
		//! 
		//! This includes any draw calls and anything else
		//! the state does, excluding events.
		//!
		//! \see Events
		void Update();

		//! \brief Called upon entering the menu state
		//! 
		//! \see TransitionExit
		void TransitionEnter();

		//! \brief Called upon exiting the menu state
		//! 
		//! \see TransitionEnter
		void TransitionExit();
	};
}

#endif // STATES_MENU_H

//! \class States::Menu
//! \ingroup states
//! 
//! Controls the menu state which should provide basic game functions.
//! Should link into options state and be the central point of the game.
//! 
//! Doesn't contain the options menu as that should be its own state.
