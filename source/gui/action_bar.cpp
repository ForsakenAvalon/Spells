
#include "gui/action_bar.h"

#include "core/gui_manager.h"
#include "gui/button.h"
#include "utility/resource_manager.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <sstream>

namespace GUI
{
	ActionBar::ActionBar( Core::GUIManager &gui_manager, const std::string &filename /* = "error.png" */ )
		: GUI::Element(gui_manager, filename)
	{
		this->buttons = new GUI::Button*[11];
		for ( int x = 0; x < 11; x++ )
			this->buttons[x] = new GUI::Button(this->gui_manager);
	}

	ActionBar::~ActionBar()
	{
		for ( int x = 0; x < 11; x++ )
		{
			std::string temp = this->buttons[x]->Filename();
			delete this->buttons[x];
			this->gui_manager.resource_manager.KillResource(temp);
		}	

		delete this->buttons;
	}

	void ActionBar::Draw()
	{
		this->gui_manager.RenderWindow().Draw(*this);
	}

	void ActionBar::PositionUpdated()
	{
		// The position of this action bar has been updated.
		// We must therefore update the position of the buttons.
	}
}
