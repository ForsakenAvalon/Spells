
#ifndef CORE_GUI_MANAGER_H
#define CORE_GUI_MANAGER_H

#include <map>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

namespace GUI
{
	class Element;
	class Button;
	class ActionBar;
}

namespace Utility
{
	class ResourceManager;
}

namespace Core
{
	class Config;

	//! \brief Manages all graphical user interface elements
	class GUIManager
	{
	public:
		typedef std::map<std::string, GUI::Element*> ElementMap;

		//! \brief Constructor
		//! 
		//! Creates a GUI manager containing three necessary references.
		//! 
		//! \param window			sf::RenderWindow reference
		//! \param config			Core::Config reference
		//! \param resource_manager Utility::ResourceManager reference
		GUIManager( sf::RenderWindow &window, Core::Config &config, Utility::ResourceManager &resource_manager );

		//! \brief Default deconstructor
		~GUIManager();

		friend class GUI::Element;
		//friend class GUI::Button;
		//friend class GUI::ActionBar;

		//! \brief Re-positions all GUI elements
		//! 
		//! Uses a new resolution to re-position all GUI elements.
		//! Attempts to place the elements in relation to their old position.
		//! 
		//! \param old_resolution_x Previous resolution width
		//! \param old_resolution_y Previous resolution height
		void UpdateElements( const float &old_resolution_x, const float &old_resolution_y );

		//! \brief Creates or retrieves an element
		//! 
		//! \param type		The type of the element, e.g. action_bar or button
		//! \param name		Unique element name
		//! \param filename Location of image (in resources/images/)
		//! 
		//! \return A newly created or existing element
		GUI::Element& Element( const std::string &type, const std::string &name, const std::string &filename = "error.png" );

		//! \brief Sets the position of an element
		//! 
		//! \param name Unique element name
		//! \param x	New x position in pixels
		//! \param y	New y position in pixels
		void SetPosition( const std::string &name, const float &x, const float &y );
		
		//! \brief Retrieve the RenderWindow
		sf::RenderWindow& RenderWindow() { return window; }

	protected:
		sf::RenderWindow &window;					//!< Reference to sf::RenderWindow
		Core::Config &config;						//!< Reference to Config
		Utility::ResourceManager &resource_manager;	//!< Reference to ResourceManager

	private:
		ElementMap elements; //!< Holds all created buttons
	};
}

#endif // CORE_GUI_MANAGER_H

//! \class Core::GUIManager
//! \ingroup core
//! 
//! Creates and stores graphical user interface elements. Manages their position
//! upon changes to resolution, attempting to keep the GUI in roughly the same place.
