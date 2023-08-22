#include "Game.h"

int main() {
	Game racing;
	racing.ConstructConsole(160, 160, 4, 4);
	racing.Start();

	return 0;
}