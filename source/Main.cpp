#include "engine/window_engine.h"

void mainGameLoop(Engine::Window & windowMain)
{
}

int main()
{
	Engine::Window MainWindow(800, 600);

	MainWindow.Run(mainGameLoop);

	return 0;
}