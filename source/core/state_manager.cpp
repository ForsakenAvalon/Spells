
#include "core/state_manager.h"

#include "base/menu.h"

namespace Core
{
	StateManager::StateManager( Core::Window &window )
		: current_state(NULL)
		, window(window)
	{
		this->states = new std::list<Base::State*>();
		this->states->push_back(new Base::Menu(States::MENU, window));
	}

	StateManager::~StateManager()
	{
		this->current_state = NULL;

		while ( !this->states->empty() )
		{
			delete this->states->front();
			this->states->pop_front();
		}
	}

	bool StateManager::Events( sf::Event &objEvent )
	{
		if ( !CheckCurrent() )
			return false;

		this->current_state->Events(objEvent);
		return true;
	}

	bool StateManager::Update()
	{
		if ( !CheckCurrent() )
			return false;

		this->current_state->Update();
		return true;
	}

	bool StateManager::SetState( const States::StateList name )
	{
		for ( std::list<Base::State*>::iterator iter = this->states->begin(); iter != this->states->end(); iter++ )
		{
			if ( name == (*iter)->GetState() )
			{
				if ( CheckCurrent() ) // If there's a current state we want to call its exit transition.
					this->current_state->TransitionExit();

				this->current_state = (*iter);

				this->current_state->TransitionEnter();

				return true;
			}
		}

		return false;
	}

	bool StateManager::CheckCurrent()
	{
		if ( this->current_state != NULL )
			return true;

		return false;
	}
}
