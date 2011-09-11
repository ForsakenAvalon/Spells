
#include "base/menu.h"

#include <iostream>

namespace Base
{
	Menu::Menu( const States::StateList state, Core::Window &window )
		: State(state, window)
	{

	}

	Menu::~Menu()
	{
		
	}

	void Menu::Events( sf::Event &objEvent )
	{
		if ( objEvent.Type == sf::Event::MouseButtonPressed )
			std::cout << objEvent.MouseButton.X << ", " << objEvent.MouseButton.Y << std::endl;
	}

	void Menu::Update()
	{
		std::cout << "Draw loop!" << std::endl;
	}

	void Menu::TransitionEnter()
	{

	}

	void Menu::TransitionExit()
	{

	}
}
