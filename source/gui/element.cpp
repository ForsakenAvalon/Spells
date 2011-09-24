
#include "gui/element.h"

#include "core/config.h"
#include "utility/resource_manager.h"
#include "utility/log.h"

#include <SFML/Graphics/Texture.hpp>

namespace GUI
{
	Element::Element( Core::GUIManager &gui_manager, const std::string &filename /* = "error.png" */ )
		: sf::Sprite()
		, gui_manager(gui_manager)
		, filename(filename)
	{
		// We call KillResource in the destructor.
		this->SetTexture(*this->gui_manager.resource_manager.GetResource<sf::Texture>(this->filename));

		this->x_pos = new float(0);
		this->y_pos = new float(0);
	}

	Element::~Element()
	{
		if ( !this->filename.empty() )
			this->gui_manager.resource_manager.KillResource(this->filename);

		delete this->x_pos;
		delete this->y_pos;
	}

	void Element::Draw()
	{
		
	}

	// Only called when the resolution has changed.
	void Element::Update()
	{
		
	}
}
