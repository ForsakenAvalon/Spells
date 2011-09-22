
#ifndef STATES_STATE_H
#define STATES_STATE_H

#include <SFML/Window/Event.hpp>

namespace Core
{
	class Window;
}

namespace StateType
{
	enum List;
}

namespace States
{
	//! \brief An abstract class used by StateManager to control the windows current state
	class State
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new state with the specified enum name and Core::Window reference.
		//! 
		//! \param state	StateType of this state
		//! \param window	Core::Window reference
		State( const StateType::List state, Core::Window &window );

		//! \brief Deconstructor
		virtual ~State();

		//! \brief Handles the specific states events
		//! 
		//! \param objEvent Event from the event loop
		virtual void Events( sf::Event &objEvent )	= 0;

		//! \brief Handles the specific states updates
		//! 
		//! This includes any draw calls, and is called after events.
		//!
		//! \see Events
		virtual void Update()						= 0;

		//! \brief Called upon entering the state
		//! 
		//! \see TransitionExit
		virtual void TransitionEnter()				= 0;

		//! \brief Called upon exiting the state
		//! 
		//! \see TransitionEnter
		virtual void TransitionExit()				= 0;


		//! \brief Returns the states name from the StateList enum
		//! 
		//! \return States::StateList name this state uses
		//! 
		//! \see States::StateList
		StateType::List GetState() { return this->my_state; }

	protected:
		StateType::List my_state;	//!< States::StateList enumeration of this state
		Core::Window &window;		//!< Reference to Core::Window
	};
}

#endif // STATES_STATE_H

//! \class States::State
//! \ingroup states
//! 
//! States are a set of classes that all control different aspects of the game.
//! Where as one state may control a menu, or an options menu, another could be
//! in control of the actual game itself; managing entities, physics and more.
//! 
//! As an abstract class it is reccomended that all inheriting classes have use
//! for each abstract function. If the Update() or Events() calls are empty no
//! drawing will be done to the screen and no events will be processed (unless
//! they are global).
//! 
//! TransitionEnter() and TransitionExit() are mainly provided for cleaning up
//! memory upon exiting the state and reinitialising memory upon entering it.
//! As states will not be deconstructed until the end of the program it is
//! essential that they don't hold lots of memory while unused.
