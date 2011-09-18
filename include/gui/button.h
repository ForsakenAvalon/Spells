
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>

#include "core/gui_manager.h"

namespace GUI
{
	class Button : public sf::Sprite
	{
	public:
		Button( const Core::GUIManager &gui_manager, const std::string &filename = "" );
		~Button();

		bool CheckClicked( const int &mouse_x, const int &mouse_y );

	private:
		Core::GUIManager gui_manager; //!< Reference to the GUI Manager.

		std::string filename;
	};
}

#endif
