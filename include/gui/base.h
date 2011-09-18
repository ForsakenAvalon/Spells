
#ifndef GUI_BASE_H
#define GUI_BASE_H

#include <string>

#include "core/gui_manager.h"
#include "utility/vector.h"

#include <SFML/Graphics/Sprite.hpp>

namespace GUI
{
	class Base : public sf::Sprite
	{
	public:
		Base( const Core::GUIManager &gui_manager, const std::string &filename = "error.png" );
		~Base();

		virtual void Draw()		= 0;
		void Update( const float &old_resolution_x, const float &old_resolution_y );

		std::string& Filename() { return filename; }

	protected:
		Core::GUIManager gui_manager;	//!< Reference to the GUI Manager.
		std::string filename;			//!< Image name.

		Utility::Vector<unsigned short int> *initial_pos;
	};
}

#endif // GUI_BASE_H
