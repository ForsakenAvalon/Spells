
#include "gui/button.h"

namespace GUI
{
	Button::Button()
		: sf::Sprite()
	{

	}

	Button::Button( const sf::Image &image )
		: sf::Sprite(image)
	{

	}

	Button::~Button()
	{

	}

	bool Button::CheckClicked( const int mouse_x, const int mouse_y )
	{
		int x_pos = (int) this->GetPosition().x;
		int y_pos = (int) this->GetPosition().y;

		int size_x = (int) this->GetSize().x;
		int size_y = (int) this->GetSize().y;

		// Is the x position of the mouse valid?
		if ( mouse_x < x_pos || mouse_x > x_pos + size_x )
			return false;

		// Is the y position of the mouse valid?
		if ( mouse_y < y_pos || mouse_y > y_pos + size_y )
			return false;

		return true;
	}
}
