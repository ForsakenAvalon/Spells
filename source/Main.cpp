
#include "core/window.h"
#include <assert.h>

#include "utility/resource_manager.h"

int main()
{
	// Initialize Game Window
	Core::Window * window;
	window = new (std::nothrow) Core::Window;

	// Assert if initialization succeded
	assert(window != NULL && "Cannot create window at main()");
	
	window->Run();

	delete window;

	return 0;
}
