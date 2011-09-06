
#ifndef BASE_STATE_H
#define BASE_STATE_H

#include <SFML/Window/Event.hpp>

namespace Core
{
	class Window;
}

namespace States
{
	enum StateList;
}

namespace Base
{
	class State
	{
	public:
		State( const States::StateList state, Core::Window &window );
		virtual ~State();

		virtual void Events( sf::Event &objEvent )	= 0;
		virtual void Update()						= 0;

		virtual void TransitionEnter()				= 0; // Transition for entering this state.
		virtual void TransitionExit()				= 0; // Transition for exiting this state.

		States::StateList GetState() { return this->my_state; }

	protected:
		States::StateList my_state;
		Core::Window &window;
	};
}

#endif // BASE_STATE_H
