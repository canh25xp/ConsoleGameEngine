#include "Game.h"

int main(){
	Game game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();

	return 0;
}
