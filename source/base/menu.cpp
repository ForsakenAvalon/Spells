
#include "base/menu.h"

#include <iostream>

namespace Base
{
	Menu::Menu( const States::StateList state, Core::Window &window )
		: State(state, window)
		, window(window)
		, options_menu_selected(false)
	{

	}

	Menu::~Menu()
	{
		
	}

	void Menu::Events( sf::Event &objEvent )
	{
		
	}

	void Menu::Update()
	{
		
	}

	void Menu::TransitionEnter()
	{
		this->options_menu_selected = false;
	}

	void Menu::TransitionExit()
	{

	}
}
