
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

	class GUIManager
	{
	public:
		typedef std::map<std::string, GUI::Button*>	ButtonMap;
		typedef std::map<std::string, GUI::ActionBar*> ActionBarMap;

		GUIManager( sf::RenderWindow &window, Core::Config &config, Utility::ResourceManager &resource_manager );
		~GUIManager();

		friend class GUI::Base;
		friend class GUI::Button;
		friend class GUI::ActionBar;

		void UpdateElements( const float &old_resolution_x, const float &old_resolution_y );

		GUI::Button&	Button( const std::string &name, const std::string &filename = "" );
		GUI::ActionBar& ActionBar( const std::string &name, const std::string &filename = "" );

		void SetPosition( const std::string &name, const float &x, const float &y );

	protected:
		sf::RenderWindow &window;					//!< Reference to sf::RenderWindow.
		Core::Config &config;						//!< Reference to Config.
		Utility::ResourceManager &resource_manager;	//!< Reference to ResourceManager.

	private:
		ButtonMap		buttons;		//!< Holds all created buttons.
		ActionBarMap	actionbars;	//!< Holds all created actionbars.
	};
}

#endif // CORE_GUI_MANAGER_H
