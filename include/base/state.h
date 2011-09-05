
#ifndef BASE_STATE_H
#define BASE_STATE_H

#ifndef NULL
#define NULL 0
#endif

#include <assert.h>
#include "utility/string.h"

// Note originally I was intending to create the entry and condition virtual so different states would inherit this, however a problem arises in the fact
// that window needs an array of possible states. Therefore I've decided to use an attach function system where Entry and Condition executed an assigned 
// function, this way window can have an array of states without a complex intermediate class.

namespace Base
{
	class State
	{
		public:
			State();
			State(unsigned int uniqueId, const char * debugName);
			~State();

			void SetEntry(void (*func)());
			void SetCondition(bool (*func)());
			bool ExcEntry();
			bool ExcCondition();

			void operator= (State & srcState);

		private:
			unsigned int id; // Unique Id of the state, this is handled by the window class
			Util::String * name; // Name of the state, used for debug purposes
			void (*ptrEntry)(); // function to call upon entering state (set by state manager)
			bool (*ptrCondition)(); // function to call before entering state to check conditions have been met (set by state manager)
			bool isPtrEntryInit;
			bool isPtrConditionInit;
	};
}

#endif