
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "gui/element.h"

#include <SFML/Window/Event.hpp>

namespace GUI
{
	//! \brief A GUI element for a button
	class Button : public GUI::Element
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new button using the image specified by filename.
		//! 
		//! \param gui_manager	Core::GUIManager reference
		//! \param filename		Location of image (in resources/images/)
		Button( Core::GUIManager &gui_manager, const std::string &filename = "error.png" );

		//! \brief Default deconstructor
		~Button();

		//! \brief Draws the button to the screen
		void Draw();

		//! \brief Returns true if this button has been clicked
		//! 
		//! Also sets the highlight/hover state of the image if
		//! hover has been set to true.
		//! 
		//! \return True if button was clicked
		bool Clicked( const sf::Event &window_event );

		//! \brief Controls whether the button has a hover-over state
		//! 
		//! If a button has a hover over state then it is directly
		//! below the actual button image (in the same file). It should
		//! be the same size with no gap in-between.
		//! 
		//! \param hover Bool to control hover state (enabled/disabled)
		void EnableHover( const bool &hover );

	private:
		bool *hover;
	};
}

#endif // GUI_BUTTON_H

//! \class GUI::Button
//! \ingroup gui
//! 
//! Holds a button. Can be used to find out whether the button was clicked
//! by calling the Clicked() member in the game event loop. Also changes
//! the buttons image if the mouse moves over it and hover is set to true.
