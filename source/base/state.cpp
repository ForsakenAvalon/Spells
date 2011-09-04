#include "base/state.h"

namespace Base
{
	State::State()
	{
		curState = -1; // Set current state as uninitialized
	}

	State::~State()
	{
	}

	bool State::ChangeState(int state)
	{
		if (curState != state) {
			curState = state;
			return true;
		}
		else {
			return false;
		}
	}

	bool State::operator= (int state)
	{
		ChangeState(state);
	}

	int State::GetCurState()
	{
		return curState;
	}
}