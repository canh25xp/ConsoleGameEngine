#include "Game.h"

int main() {
	Game racing;
	racing.ConstructConsole(200, 160, 4, 4);
	racing.Start();

	return 0;
}