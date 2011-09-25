
#include "gui/element.h"

#include "core/gui_manager.h"
#include "core/config.h"
#include "utility/resource_manager.h"

#include <SFML/Graphics/Texture.hpp>

namespace GUI
{
	Element::Element( Core::GUIManager &gui_manager, const std::string &filename /* = "error.png" */ )
		: sf::Sprite()
		, gui_manager(gui_manager)
		, filename(filename)
	{
		// We call KillResource in the destructor.
		this->SetTexture(*this->gui_manager.resource_manager.GetResource<sf::Texture>(this->filename));

		this->gui_x_position	= new short int(0);
		this->gui_y_position	= new short int(0);
		this->gui_central		= new bool(true);
	}

	Element::~Element()
	{
		delete this->gui_x_position;
		delete this->gui_y_position;
		delete this->gui_central;
	}

	void Element::Draw()
	{
		
	}

	// Only called when the resolution has changed.
	void Element::Update()
	{
		float screen_width	= static_cast<float>(this->gui_manager.config.GetResolution().x);
		float screen_height	= static_cast<float>(this->gui_manager.config.GetResolution().y);

		float x_position;
		float y_position;

		// Convert GUI coords to screen pixels to obtain the elements x position.
		if ( *this->gui_x_position == 0 )
		{
			if ( *this->gui_central )
				x_position = ( screen_width - this->GetSize().x ) / 2.f;
			else
				x_position = 0;
		}
		else if ( *this->gui_x_position < 0 )
			x_position = screen_width + *this->gui_x_position;
		else
			x_position = *this->gui_x_position;

		// Convert GUI coords to screen pixels to obtain the elements y position.
		if ( *this->gui_y_position == 0 )
		{
			if ( *this->gui_central )
				y_position = ( screen_height - this->GetSize().y ) / 2.f;
			else
				y_position = 0;
		}
		else if ( *this->gui_y_position < 0 )
			y_position = screen_height + *this->gui_y_position;
		else
			y_position = *this->gui_y_position;

		// Assign the new position to this element.
		this->SetPosition(x_position, y_position);
	}

	void Element::SetGUICoords( const short int &x_position, const short int &y_position, const bool &central )
	{
		*this->gui_x_position	= x_position;
		*this->gui_y_position	= y_position;
		*this->gui_central		= central;

		// If the position is changed we need to update it.
		this->Update();
	}
}
