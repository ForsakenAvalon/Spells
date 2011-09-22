
#ifndef GUI_ACTION_BAR_H
#define GUI_ACTION_BAR_H

#include "gui/base.h"

namespace GUI
{
	//! \brief A GUI element for an action bar
	class ActionBar : public GUI::Base
	{
	public:
		//! \brief Constructor
		//! 
		//! Creates a new action bar using the image specified by filename.
		//! 
		//! \param gui_manager	Core::GUIManager reference
		//! \param filename		Location of image (in resources/images/)
		ActionBar( const Core::GUIManager &gui_manager, const std::string &filename = "error.png" );

		//! \brief Default deconstructor
		~ActionBar();

		//! \brief Draws the action bar to the screen
		void Draw();

		//! \brief Called when the position of the action bar is updated
		//! 
		//! Used to update the position of all the action bars button members.
		void PositionUpdated();

	private:
		GUI::Button **buttons; //!< Holds all of the buttons in this action bar
	};
}

#endif // GUI_ACTION_BAR_H

//! \class GUI::ActionBar
//! \ingroup gui
//! 
//! Holds an action bar and manages it's buttons.
