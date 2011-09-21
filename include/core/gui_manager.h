
#ifndef CORE_GUI_MANAGER_H
#define CORE_GUI_MANAGER_H

#include <map>
#include <string>

namespace sf
{
	class RenderWindow;
}

namespace GUI
{
	class Base;
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
		typedef std::map<std::string, GUI::Button*>	ButtonMap;
		typedef std::map<std::string, GUI::ActionBar*> ActionBarMap;

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

		friend class GUI::Base;
		friend class GUI::Button;
		friend class GUI::ActionBar;

		//! \brief Re-positions all GUI elements
		//! 
		//! Uses a new resolution to re-position all GUI elements.
		//! Attempts to place the elements in relation to their old position.
		//! 
		//! \param old_resolution_x Previous resolution width
		//! \param old_resolution_y Previous resolution height
		void UpdateElements( const float &old_resolution_x, const float &old_resolution_y );

		//! \brief Creates or retrieves a button element
		//! 
		//! \param name		Unique button name
		//! \param filename Location of image (in resources/images/)
		//! 
		//! \return A newly created or existing button
		GUI::Button& Button( const std::string &name, const std::string &filename = "" );

		//! \brief Creates or retrieves an action bar element
		//! 
		//! \param name		Unique action bar name
		//! \param filename Location of image (in resources/images/)
		//! 
		//! \return A newly created or existing action bar
		GUI::ActionBar& ActionBar( const std::string &name, const std::string &filename = "" );

		//! \brief Sets the position of an element
		//! 
		//! Will not function correctly if two different elements
		//! have the same unique name.
		//! 
		//! \param name Unique element name
		//! \param x	New x position in pixels
		//! \param y	New y position in pixels
		void SetPosition( const std::string &name, const float &x, const float &y );

	protected:
		sf::RenderWindow &window;					//!< Reference to sf::RenderWindow.
		Core::Config &config;						//!< Reference to Config.
		Utility::ResourceManager &resource_manager;	//!< Reference to ResourceManager.

	private:
		ButtonMap		buttons;	//!< Holds all created buttons.
		ActionBarMap	actionbars;	//!< Holds all created actionbars.
	};
}

#endif // CORE_GUI_MANAGER_H

//! \class Core::GUIManager
//! \ingroup core
//! 
//! Creates and stores graphical user interface elements. Manages their position
//! upon changes to resolution, attempting to keep the GUI in roughly the same place.
