
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>

namespace GUI
{
	class Button : public sf::Sprite
	{
	public:
		Button();
		Button( const sf::Image &image );

		~Button();

		bool CheckClicked( const int mouse_x, const int mouse_y );
	};
}

#endif
