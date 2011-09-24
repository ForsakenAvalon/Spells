
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include "core/gui_manager.h"

#include <string>

#include <SFML/Graphics/Sprite.hpp>

namespace GUI
{
	//! \brief Base GUI class, all GUI elements should inherit from this
	class Element : public sf::Sprite
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new graphical user interface instance.
		//! 
		//! \param gui_manager	Core::GUIManager reference
		//! \param filename		Location of image (in resources/images/)
		Element( Core::GUIManager &gui_manager, const std::string &filename = "error.png" );

		//! \brief Default deconstructor
		virtual ~Element();

		//! \brief Draws this element to the window.
		virtual void Draw() = 0;

		//! \brief Updates this element to a new resolution
		//! 
		//! \param old_resolution_x Previous window resolution width
		//! \param old_resolution_y Previous window resolution height
		void Update( const float &old_resolution_x, const float &old_resolution_y );

		//! \brief Returns the image name used for this element
		//! 
		//! \return Image name for the image this element uses
		std::string& Filename() { return filename; }

	protected:
		Core::GUIManager &gui_manager;	//!< Reference to the GUI Manager
		std::string filename;			//!< Image name
	};
}

#endif // GUI_ELEMENT_H

//! \class GUI::Element
//! \ingroup gui
//! 
//! A base class for all graphical user interface elements which provides
//! basic functions needed for any element of the interface.
//! 
//! Inherits from sf::Sprite which is used to draw the element to the screen.
//! If a filename is not passed then the sprite will simply load an error image
//! to notify that the specified image couldn't be loaded.
