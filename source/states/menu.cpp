
#include "states/menu.h"

#include <iostream>

namespace States
{
	Menu::Menu( const StateType::List state, Core::Window &window )
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
