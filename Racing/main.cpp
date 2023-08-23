#include "Game.h"

int main() {
	Game racing;
	racing.ConstructConsole(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_SIZE, PIXEL_SIZE);
	racing.Start();

	return 0;
}