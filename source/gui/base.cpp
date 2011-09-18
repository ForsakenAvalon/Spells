
#include "gui/base.h"

#include "utility/resource_manager.h"
#include "core/config.h"

namespace GUI
{
	Base::Base( const Core::GUIManager &gui_manager, const std::string &filename /* = "" */ )
		: sf::Sprite()
		, gui_manager(gui_manager)
		, filename(filename)
	{
		// We call KillResource in the gui_manager destructor.
		this->SetImage(*this->gui_manager.resource_manager.GetResource<sf::Image>(filename));

		this->initial_pos = new Utility::Vector<unsigned short int>((unsigned short int) this->GetPosition().x, (unsigned short int) this->GetPosition().y);
	}

	Base::~Base()
	{
		delete this->initial_pos;
	}

	void Base::Draw()
	{
		
	}

	// Only called when the resolution has changed.
	void Base::Update( const unsigned short int &old_resolution_x, const unsigned short int &old_resolution_y )
	{
		unsigned short int window_width = this->gui_manager.config.GetResolution().x;
		unsigned short int window_height = this->gui_manager.config.GetResolution().y;

		unsigned short int scale_factor_x = window_width / old_resolution_x;
		unsigned short int scale_factor_y = window_height / old_resolution_y;

		this->SetPosition(this->GetPosition().x * (float) scale_factor_x, this->GetPosition().y * (float) scale_factor_y);
	}
}
