
#ifndef GUI_ACTION_BAR_H
#define GUI_ACTION_BAR_H

#include "gui/button.h"
#include "utility/resource_manager.h"

namespace sf
{
	class RenderWindow;
	class Sprite;
}

namespace Core
{
	class Config;
}

namespace GUI
{
	class ActionBar
	{
	public:
		ActionBar( sf::RenderWindow &window, Core::Config &config, Utility::ResourceManager &resource_manager );
		~ActionBar();

		void Update();

	private:
		void Draw();

		sf::RenderWindow &window;
		Core::Config &config;
		Utility::ResourceManager &resource_manager;

		GUI::Button		**buttons;
		sf::Sprite		*actionbar;

		unsigned short int *last_res_width;		//!< Holds the last resolution used to position the action bar.
		unsigned short int *last_res_height;	//!< Holds the last resolution used to position the action bar.

		float *position_x;	//!< Holds the x screen position of the action bar.
		float *position_y;	//!< Holds the y screen position of the action bar.
	};
}

#endif // GUI_ACTION_BAR_H
