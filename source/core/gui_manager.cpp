
#include "core/gui_manager.h"

#include "gui/button.h"
#include "gui/action_bar.h"
#include "utility/log.h"
#include "utility/resource_manager.h"

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
		// Remove elements and then kill their image resources.
		for ( ButtonMap::const_iterator iter = this->buttons.begin(); iter != this->buttons.end(); iter++ )
		{
			std::string temp = iter->second->Filename();
			delete iter->second;
			this->resource_manager.KillResource(temp);
		}

		for ( ActionBarMap::const_iterator iter = this->actionbars.begin(); iter != this->actionbars.end(); iter++ )
		{
			std::string temp = iter->second->Filename();
			delete iter->second;
			this->resource_manager.KillResource(temp);
		}
	}

	GUI::Button& GUIManager::Button( const std::string &name, const std::string &filename /* = "" */ )
	{
		ButtonMap::const_iterator iter = this->buttons.find(name);
		if ( iter == this->buttons.end() )
		{
			if ( filename.empty() )
			{
				Utility::Log log("gui_manager.txt");
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
				Utility::Log log("gui_manager.txt");
				log.Write("Trying to initialise action bar with no filename.");
				log.EndLine();
			}

			this->actionbars[name] = new GUI::ActionBar(*this, filename);
		}

		return *this->actionbars[name];
	}

	void GUIManager::SetPosition( const std::string &name, const float &x, const float &y )
	{
		ButtonMap::const_iterator iter = this->buttons.find(name);
		if ( iter == this->buttons.end() )
		{
			ActionBarMap::const_iterator iter = this->actionbars.find(name);
			if ( iter == this->actionbars.end() )
			{
				Utility::Log log("gui_manager.txt");
				log.Write("Cannot set position of inexistant item.");
				log.EndLine();
				return;
			}

			// We have found an action bar.
			iter->second->SetPosition(x, y);
			return;
		}

		// We have found a button.
		iter->second->SetPosition(x, y);
	}
}
