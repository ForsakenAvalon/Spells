
#include "core/gui_manager.h"

#include "gui/button.h"
#include "gui/action_bar.h"
#include "utility/log.h"

namespace Core
{
	GUIManager::GUIManager( sf::RenderWindow &window, Core::Config &config, Utility::ResourceManager &resource_manager )
		: window(window)
		, config(config)
		, resource_manager(resource_manager)
	{
		
	}

	GUIManager::~GUIManager()
	{
		for ( ButtonMap::const_iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++ )
			delete iter->second;

		for ( ActionBarMap::const_iterator iter = this->actionbars.begin(); iter != this->actionbars.end(); iter++ )
			delete iter->second;
	}

	GUI::Button& GUIManager::Button( const std::string &name, const std::string &filename /* = "" */ )
	{
		ButtonMap::const_iterator iter = this->buttons.find(name);
		if ( iter == this->buttons.end() )
		{
			if ( filename.empty() )
			{
				Utility::Log log("gui_manager.cpp");
				log.Write("Trying to initialise button with no filename.");
				log.EndLine();
			}

			this->buttons[name] = new GUI::Button(*this, filename);
		}

		return *this->buttons[name];
	}

	GUI::ActionBar& GUIManager::ActionBar( const std::string &name, const std::string &filename /* = "" */ )
	{
		ActionBarMap::const_iterator iter = this->actionbars.find(name);
		if ( iter == this->actionbars.end() )
		{
			if ( filename.empty() )
			{
				Utility::Log log("gui_manager.cpp");
				log.Write("Trying to initialise action bar with no filename.");
				log.EndLine();
			}

			this->actionbars[name] = new GUI::ActionBar(*this, filename);
		}

		return *this->actionbars[name];
	}
}
