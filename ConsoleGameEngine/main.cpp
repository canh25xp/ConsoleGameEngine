#include "Game.h"

int main() {
	Game game;
	game.ConstructConsole(100, 100, 4, 4);
	game.Start();

	return 0;
}
