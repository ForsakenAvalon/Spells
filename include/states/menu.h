
#ifndef STATES_MENU_H
#define STATES_MENU_H

#include "states/state.h"

namespace Core
{
	class Window;
}

namespace States
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

#endif // STATES_MENU_H
