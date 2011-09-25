
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include <string>

#include <SFML/Graphics/Sprite.hpp>

namespace Core
{
	class GUIManager;
}

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
		void Update();

		//! \brief Sets the gui position of the element
		//! 
		//! GUI position works from the edges of the screen. Elements should
		//! be positioned as so (relative to screen):
		//! 
		//! - Positive x & y specify the x/y position from the top left
		//! - Negative x & y specify the x/y position from the bottom right
		//! - 0 specifies centrarl unless no_central is true
		//!
		//! \param x_position x position of element as described above
		//! \param y_position y position of element as described above
		//! \param no_central Whether this element will be centered for 0 values
		void SetGUICoords( const short int &x_position, const short int &y_position, const bool &central );

		//! \brief Returns the image name used for this element
		//! 
		//! \return Image name for the image this element uses
		std::string& Filename() { return filename; }

	protected:
		Core::GUIManager &gui_manager;	//!< Reference to the GUI Manager
		std::string filename;			//!< Image name

		short int *gui_x_position;		// x position in GUI coords
		short int *gui_y_position;		// y position in GUI coords
		bool *gui_central;					// Whether 0 represents the screen center for this element
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
