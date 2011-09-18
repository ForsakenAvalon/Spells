
#include "gui/action_bar.h"

#include "core/window.h"
#include "core/config.h"

namespace GUI
{
	ActionBar::ActionBar( sf::RenderWindow &window, Core::Config &config, Utility::ResourceManager &resource_manager, const std::string &filename )
		: window(window)
		, config(config)
		, resource_manager(resource_manager)
	{
		this->filename = new std::string(filename);

		this->position_x = new float();
		this->position_y = new float();

		this->actionbar = new sf::Sprite(*this->resource_manager.GetResource<sf::Image>(*this->filename));
		this->buttons = new GUI::Button*[11];

		for ( int x = 0; x < 11; x++ )
			this->buttons[x] = new GUI::Button();

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
		this->resource_manager.KillResource(*this->filename);

		delete this->last_res_width;
		delete this->last_res_height;

		delete this->position_x;
		delete this->position_y;

		delete this->filename;
	}

	void ActionBar::Update()
	{
		unsigned short int width = this->config.GetResolution().x;
		unsigned short int height = this->config.GetResolution().y;

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
		this->window.Draw(*this->actionbar);
	}
}
