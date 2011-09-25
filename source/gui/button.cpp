
#include "gui/button.h"

#include "core/gui_manager.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace GUI
{
	Button::Button( Core::GUIManager &gui_manager, const std::string &filename /* = "error.png" */ )
		: GUI::Element(gui_manager, filename)
	{
		this->hover = new bool(false);
	}

	Button::~Button()
	{
		delete this->hover;
	}

	void Button::Draw()
	{
		this->gui_manager.RenderWindow().Draw(*this);
	}

	bool Button::Clicked( const sf::Event &window_event )
	{
		float x_pos = this->GetPosition().x;
		float y_pos = this->GetPosition().y;

		float size_x, size_y;

		if ( hover )
		{
			size_x = this->GetSize().x / 2;
			size_y = this->GetSize().y / 2;
		}
		else
		{
			size_x = this->GetSize().x;
			size_y = this->GetSize().y;
		}

		// Check x position of mouse.
		if ( window_event.MouseButton.X < x_pos || window_event.MouseButton.X > x_pos + size_x )
			return false;

		// Check y position of mouse.
		if ( window_event.MouseButton.Y < y_pos || window_event.MouseButton.Y > y_pos + size_y )
			return false;

		// The mouse is over the button, so highlight it.
		if ( this->hover )
			this->SetSubRect(sf::IntRect(0, 0 + (int) size_y, (int) size_x, 0 + (int) size_y + (int) size_y));

		if ( window_event.Type != sf::Event::MouseButtonReleased )
			return false;

		return true;
	}

	void Button::EnableHover( const bool &hover )
	{
		*this->hover = hover;

		if ( hover )
			this->SetSubRect(sf::IntRect(0, 0, (int) this->GetSize().x / 2, (int) this->GetSize().y / 2));
		else
			this->SetSubRect(sf::IntRect(0, 0, (int) this->GetSize().x, (int) this->GetSize().y));
	}
}
