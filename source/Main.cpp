
#include "engine/window_engine.h"
#include <assert.h>

int main()
{
	// Initialize Game Window
	Engine::Window * window;
	window = new(std::nothrow) Engine::Window;

	// Assert if initialization succeded
	assert(NULL != window && "Cannot create window at main()");
	
	window->Run();

	return 0;
}
