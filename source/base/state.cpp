#include "base/state.h"

namespace Base
{
	//! /brief Initialize State Class
	//! /param uniqueId : unique Id assigned to states
	State::State(unsigned int uniqueId)
	{
		id = uniqueId;
		isPtrEntryInit = false;
		isPtrConditionInit = false;
	}

	//! /brief Cleanup State Class
	State::~State()
	{
		if (isPtrEntryInit) {
			this->isPtrEntryInit = 0;
		}
		if (isPtrConditionInit) {
			this->isPtrConditionInit = 0;
		}
	}

	//! /brief Assign entry function for state
	//! /descrip Assigns an entry function that is exectued when the program
	//! enters this state. Assigning is handled by the StateManager class.
	//! /param func : Function to execute, should take no parameters and
	//! return a void value
	void State::SetEntry(void (*func)())
	{
		this->ptrEntry = func;
	}

	//! /brief Assign condition function for state
	//! /descrip Assigns a condition function that is executed when the program
	//! [b]tries[/b] to enter this state. StateManager calls this to see if the
	//! program can enter this state. Assigning is handled by the StateManager
	//! class. 
	//! /param func : Function to execute, should take no parameters and return
	//! a boolean value.
	void State::SetCondition(bool (*func)())
	{
		this->ptrCondition = func;
	}

	//! /brief Function on Entry to State
	//! /descrip Executes the entry function of the state. The StateManager 
	//! runs this after running ExcCondition().
	//! /return true if function is executed, false otherwise.
	bool State::ExcEntry()
	{
		if (isPtrEntryInit) {
			this->ptrEntry();
			return true;
		}
		else {
			return false;
		}
	}

	//! /brief Function before Entry to State
	//! /descrip Excutes the conditional function of the state. The StateManager
	//! runs this to check if entering the state is possible.
	//! /return matches value of conditional function unless its not set, 
	//! in which case returns false.
	bool State::ExcCondition()
	{
		if (isPtrConditionInit) {
			if (this->ptrCondition()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}