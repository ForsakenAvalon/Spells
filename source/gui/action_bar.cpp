
#include "gui/action_bar.h"


#include "core/config.h"
#include "utility/resource_manager.h"
#include "gui/button.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace GUI
{
	ActionBar::ActionBar( const Core::GUIManager &gui_manager, const std::string &filename )
		: gui_manager(gui_manager)
		, filename(filename)
	{
		this->position_x = new float();
		this->position_y = new float();

		this->actionbar = new sf::Sprite(*this->gui_manager.resource_manager.GetResource<sf::Image>(this->filename));
		this->buttons = new GUI::Button*[11];

		for ( int x = 0; x < 11; x++ )
			this->buttons[x] = new GUI::Button(this->gui_manager);

		this->last_res_width	= new unsigned short int();
		this->last_res_height	= new unsigned short int();

		*this->last_res_width	= 0;
		*this->last_res_height	= 0;
	}

	ActionBar::~ActionBar()
	{
		for ( int x = 0; x < 11; x++ )
			delete this->buttons[x];

		delete this->buttons;
		delete this->actionbar;
		this->gui_manager.resource_manager.KillResource(this->filename);

		delete this->last_res_width;
		delete this->last_res_height;

		delete this->position_x;
		delete this->position_y;
	}

	void ActionBar::Update()
	{
		unsigned short int width = this->gui_manager.config.GetResolution().x;
		unsigned short int height = this->gui_manager.config.GetResolution().y;

		if ( *this->last_res_width == width && *this->last_res_height == height )
		{
			this->Draw();
			return;
		}

		// Resolution/window size has changed therefore we must update the action bar.
		// The action bar should be centered at the bottom of the screen.
		*this->last_res_width = width;
		*this->last_res_height = height;

		*this->position_x = (width - this->actionbar->GetSize().x) / 2;
		*this->position_y = height - this->actionbar->GetSize().y;

		this->actionbar->SetPosition(*this->position_x, *this->position_y);

		this->Draw();
	}

	void ActionBar::Draw()
	{
		this->gui_manager.window.Draw(*this->actionbar);
	}
}
