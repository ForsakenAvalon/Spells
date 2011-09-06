
#ifndef BASE_MENU_H
#define BASE_MENU_H

#include "base/state.h"

namespace Base
{
	class Menu : public State
	{
	public:
		Menu( const States::StateList state, Core::Window &window );
		~Menu();

		void Events( sf::Event &objEvent );
		void Update();

		void TransitionEnter();
		void TransitionExit();
	};
}

#endif // BASE_MENU_H
