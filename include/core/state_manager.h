
#ifndef CORE_STATE_MANAGER_H
#define CORE_STATE_MANAGER_H

#include <list>

#include <SFML/Window/Event.hpp>

namespace Core
{
	class Window;
}

namespace States
{
	class State;
}

namespace StateType
{
	//! \brief Holds all possible states
	//! 
	//! Contains an element for each state to enable states
	//! to be easily referenced across classes.
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
	//! \brief Manages all classes inherited from Base::State
	class StateManager
	{
	public:
		//! \brief Constructor
		StateManager( Core::Window &window );

		//! \brief Deconstructor
		~StateManager();

		//! \brief Calls the current states Events function
		//! 
		//! \param objEvent Window loop event
		//! 
		//! \return Returns false if a state isn't set
		bool Events( sf::Event &objEvent );
		
		//! \brief Calls the current states Update function
		//! 
		//! \return Returns false if a state isn't set
		bool Update();

		//! \brief Changes the current state to the specified state
		//! 
		//! \param name Enumerator representation of the state
		//! 
		//! \return Whether the state could be set
		bool SetState( const StateType::List name );

	private:
		//! \brief Assess whether a state has been set
		//! 
		//! \return Validity of current_state
		bool CheckCurrent();

		std::list<States::State*> *states;	//!< Contains all states
		States::State *current_state;		//!< Holds the current state

		Core::Window &window;				//!< Core::Window reference
	};
}

#endif // CORE_STATE_MANAGER_H
