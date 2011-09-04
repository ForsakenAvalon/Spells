
#ifndef BASE_STATE_H
#define BASE_STATE_H

#include <string>
#include <map>

namespace Base
{
	class State
	{
		public:
			enum Type 
			{
				MAIN_MENU = 0,
				RUNNING,
				_COUNT // Stores total number of states in the game
			};
			
			State();
			~State();

			bool ChangeState	(int state);
			bool operator=		(int state);

			int GetCurState();
		private:
			int curState;
	};
}

#endif // BASE_STATE_H
