
#include "core/window.h"
#include <assert.h>

<<<<<<< HEAD
#include "utility/resource_manager.h"

=======
>>>>>>> 22cb710905185047480f77f4a09522eeffa1f60a
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
