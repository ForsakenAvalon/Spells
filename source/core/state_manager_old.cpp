
#include "core/state_manager.h"

namespace Core
{
	StateManager::StateManager(Window * window)
	{
		objWindow = window;
		totalStateCount = 0;
		curStateId = 0;
	}

	StateManager::~StateManager()
	{
		objWindow = 0; 
	}

	void StateManager::AddState(const char * debugName, void (*entryFunc)(), bool (*conditionFunc)())
	{
		if (totalStateCount != 0) {
			Base::State * tempStateArray;
			Base::State * tempState;

			tempStateArray = new Base::State[this->totalStateCount];
			totalStateCount++;

			for (unsigned int x = 0; x < totalStateCount; x++) {
				tempStateArray[x] = objWindow->objState[x];
			}

			objWindow->objState = new Base::State[totalStateCount];
			
			for (unsigned int x = 0; x < totalStateCount; x++) {
				objWindow->objState[x] = tempStateArray[x];
			}

			tempState = new Base::State(totalStateCount, debugName);
			tempState->SetEntry(entryFunc);
			tempState->SetCondition(conditionFunc);
		
			objWindow->objState[totalStateCount] = *(tempState);
			
			delete [] tempStateArray;
			delete tempState;
		}
	}

	bool StateManager::Transistion(unsigned int stateId)
	{
		// Check if conditions met for entering state
		if (objWindow->objState[stateId].ExcCondition()) {
			// Condition met, proceed with entry function and change current state
			objWindow->objState[stateId].ExcEntry();
			curStateId = stateId;
			return true;
		}
		else {
			return false;
		}
	}
}