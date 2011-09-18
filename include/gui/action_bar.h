
#ifndef GUI_ACTION_BAR_H
#define GUI_ACTION_BAR_H

#include "gui/base.h"

namespace GUI
{
	class ActionBar : public GUI::Base
	{
	public:
		ActionBar( const Core::GUIManager &gui_manager, const std::string &filename = "error.png" );
		~ActionBar();

		void Draw();
		void PositionUpdated();

	private:
		GUI::Button **buttons;
	};
}

#endif // GUI_ACTION_BAR_H
