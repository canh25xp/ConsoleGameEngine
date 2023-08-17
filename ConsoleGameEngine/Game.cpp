#include "Game.h"

using namespace cge;

Game::Game() {
	score = 0;
}

bool Game::OnUserCreate() {
	Fill(0, 0, ScreenWidth(), ScreenHeight(), ' ', cge::COLOR::BG_MAGENTA);
	DrawString(10, 10, L"Hello World", cge::COLOR::BG_MAGENTA + cge::COLOR::FG_WHITE);
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	for (int x = 0; x < ScreenWidth(); x++)
		for (int y = 0; y < ScreenHeight(); y++)
			Draw(x, y, ' ', rand() % 255);
	return true;
}