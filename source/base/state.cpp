
#include "base/state.h"

namespace Base
{
	State::State( StateType::List state, Core::Window &window )
		: my_state(state)
		, window(window)
	{

	}

	State::~State()
	{

	}
	void State::Events( sf::Event &objEvent )
	{

	}

	void State::Update()
	{

	}

	void State::TransitionEnter()
	{

	}

	void State::TransitionExit()
	{

	}
}
