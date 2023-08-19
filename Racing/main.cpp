#include "Game.h"

int main() {
	Game game;
	game.ConstructConsole(60, 80, 8, 8);
	game.Start();

	return 0;
}