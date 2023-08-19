#include "Game.h"

int main() {
	Game game;
	game.ConstructConsole(120, 160, 4, 4);
	game.Start();

	return 0;
}