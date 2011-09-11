
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

	Util::String A("Hello");
	Util::String B("World!");
	Util::String C;

	C = A + B;
	std::cout<< C.ToTextStatic();
	std::cin.get();

	delete window;

	return 0;
}
