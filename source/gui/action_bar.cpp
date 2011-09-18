
#include "gui/action_bar.h"

#include "gui/button.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace GUI
{
	ActionBar::ActionBar( const Core::GUIManager &gui_manager, const std::string &filename /* = "" */ )
		: GUI::Base(gui_manager, filename)
	{
		this->buttons = new GUI::Button*[11];
		for ( int x = 0; x < 11; x++ )
			this->buttons[x] = new GUI::Button(gui_manager);
	}

	ActionBar::~ActionBar()
	{
		for ( int x = 0; x < 11; x++ )
			delete this->buttons[x];

		delete this->buttons;
	}

	void ActionBar::Draw()
	{
		this->gui_manager.window.Draw(*this);
	}

	void ActionBar::PositionUpdated()
	{
		// The position of this action bar has been updated.
		// We must therefore update the position of the buttons.
	}
}
