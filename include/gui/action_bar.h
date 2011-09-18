
#ifndef GUI_ACTION_BAR_H
#define GUI_ACTION_BAR_H

#include <string>
#include "core/gui_manager.h"

namespace sf
{
	class RenderWindow;
	class Sprite;
}

namespace Core
{
	//class GUIManager;
	class Config;
}

namespace Utility
{
	class ResourceManager;
}

namespace GUI
{
	class Button;

	class ActionBar
	{
	public:
		ActionBar( const Core::GUIManager &gui_manager, const std::string &filename );
		~ActionBar();

		void Update();

	private:
		void Draw();

		Core::GUIManager gui_manager;	//!< Reference to the GUI Manager.

		GUI::Button		**buttons;	//!< Holds a button for each button on the action bar.
		sf::Sprite		*actionbar;	//!< Holds the action bar's sprite.

		std::string filename;	//!< Holds the filename of the image for this actionbar.

		unsigned short int *last_res_width;		//!< Holds the last resolution used to position the action bar.
		unsigned short int *last_res_height;	//!< Holds the last resolution used to position the action bar.

		float *position_x;	//!< Holds the x screen position of the action bar.
		float *position_y;	//!< Holds the y screen position of the action bar.
	};
}

#endif // GUI_ACTION_BAR_H
