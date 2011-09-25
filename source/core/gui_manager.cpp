
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
		// Remove elements.
		for ( ElementMap::const_iterator iter = this->elements.begin(); iter != this->elements.end(); iter++ )
		{
			GUI::Element *element = iter->second;
			std::string temp = element->Filename();
			delete element;
			this->resource_manager.KillResource(temp);
		}

		this->elements.clear();
	}

	void GUIManager::UpdateElements()
	{
		for ( ElementMap::const_iterator iter = this->elements.begin(); iter != this->elements.end(); iter++ )
			iter->second->Update();
	}

	GUI::Element& GUIManager::Element( const std::string &type, const std::string &name, const std::string &filename /* = "error.png" */ )
	{
		ElementMap::const_iterator iter = this->elements.find(name);
		if ( iter != this->elements.end() )
			return *this->elements[name];

		if ( filename.empty() || filename == "error.png" )
		{
			Utility::Log log("gui_manager.txt");
			log.Write("Trying to initialise element with improper filename.");
			log.EndLine();
		}

		if ( type == "action_bar" )
			this->elements[name] = new GUI::ActionBar(*this, filename);
		else if ( type == "button" )
			this->elements[name] = new GUI::Button(*this, filename);

		return *this->elements[name];
	}
}
