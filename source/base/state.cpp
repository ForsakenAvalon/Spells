#include "base/state.h"

namespace Base
{
	State::State(unsigned int uniqueId)
	{
		id = uniqueId;
		isPtrEntryInit = false;
		isPtrConditionInit = false;
	}

	State::~State()
	{
		if (isPtrEntryInit) {
			this->isPtrEntryInit = 0;
		}
		if (isPtrConditionInit) {
			this->isPtrConditionInit = 0;
		}
	}
}