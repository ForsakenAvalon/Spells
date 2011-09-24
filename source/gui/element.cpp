
#include "gui/element.h"

#include "core/config.h"
#include "utility/resource_manager.h"
#include "utility/log.h"

#include <SFML/Graphics/Texture.hpp>

// debug
#include <iostream>

namespace GUI
{
	Element::Element( Core::GUIManager &gui_manager, const std::string &filename /* = "error.png" */ )
		: sf::Sprite()
		, gui_manager(gui_manager)
		, filename(filename)
	{
		// We call KillResource in the destructor.
		this->SetTexture(*this->gui_manager.resource_manager.GetResource<sf::Texture>(this->filename));
	}

	Element::~Element()
	{
		if ( !this->filename.empty() )
			this->gui_manager.resource_manager.KillResource(this->filename);
	}

	void Element::Draw()
	{
		
	}

	// Only called when the resolution has changed.
	void Element::Update( const float &old_resolution_x, const float &old_resolution_y )
	{
		float window_width	= (float) this->gui_manager.config.GetResolution().x;
		float window_height = (float) this->gui_manager.config.GetResolution().y;

		std::cout << "New window width: " << window_width << std::endl;
		std::cout << "New window height: " << window_height << std::endl;
		std::cout << "Old window width: " << old_resolution_x << std::endl;
		std::cout << "Old window height: " << old_resolution_y << std::endl;

		float scale_factor_x = window_width / old_resolution_x;
		float scale_factor_y = window_height / old_resolution_y;

		std::cout << "x scale factor: " << scale_factor_x << std::endl;
		std::cout << "y scale factor: " << scale_factor_y << std::endl;

		std::cout << "x position: " << this->GetPosition().x << std::endl;
		std::cout << "y position: " << this->GetPosition().y << std::endl;

		float new_position_x = this->GetPosition().x * scale_factor_x;
		float new_position_y = this->GetPosition().y * scale_factor_y;

		std::cout << "New position: " << new_position_x << ", " << new_position_y << std::endl;

		this->SetPosition(new_position_x, new_position_y);
	}
}
