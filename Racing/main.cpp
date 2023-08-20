#include "Game.h"
#include <iostream>

int main() {
	Game game;
	game.ConstructConsole(120, 160, 4, 4);
	game.Start();

	return 0;
}