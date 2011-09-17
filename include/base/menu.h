
#ifndef BASE_MENU_H
#define BASE_MENU_H

#include "base/state.h"

namespace Core
{
	class Window;
}

namespace Base
{
	class Menu : public State
	{
	public:
		Menu( const StateType::List state, Core::Window &window );
		~Menu();

		void Events( sf::Event &objEvent );
		void Update();

		void TransitionEnter();
		void TransitionExit();

	private:
		Core::Window &window;

		bool options_menu_selected;
	};
}

#endif // BASE_MENU_H
