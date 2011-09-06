
#include "base/state.h"

namespace Base
{
	State::State( States::StateList state, Core::Window &window )
		: my_state(state)
		, window(window)
	{

	}

	State::~State()
	{

	}
	void State::Events( sf::Event objEvent )
	{

	}

	void State::Update()
	{

	}
<<<<<<< HEAD

	void State::TransitionEnter()
	{

	}

	void State::TransitionExit()
	{

	}
=======
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a
}
