#include "Game.h"

int main() {
	Game racing;
	racing.ConstructConsole(100, 100, 4, 4);
	racing.Start();

	return 0;
}