
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "gui/base.h"

#include <SFML/Window/Event.hpp>

namespace GUI
{
	class Button : public GUI::Base
	{
	public:
		Button( const Core::GUIManager &gui_manager, const std::string &filename = "error.png" );
		~Button();

		void Draw();

		bool Clicked( const sf::Event &window_event );
		void EnableHover( const bool &hover );

	private:
		bool *hover;
	};
}

#endif // GUI_BUTTON_H
