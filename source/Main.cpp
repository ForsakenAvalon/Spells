
#include "core/window.h"
#include "utility\string.h"
#include <assert.h>
#include <iostream>

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
