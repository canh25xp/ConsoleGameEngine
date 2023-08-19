#include "Game.h"

Game::Game() {
	m_sAppName = L"Racing";
	m_car.spr_car = nullptr;
	exit = false;
}

bool Game::OnUserCreate() {
	m_car.spr_car = new Sprite(L"assets/car1.spr");
	score = 0;
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	if (m_keys[VK_ESCAPE].bPressed)
		return false;

	if(m_keys[VK_UP].bPressed){
		m_car.position.MoveUp(4);
	}

void Game::ClearScreen() {
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_BLANK, BACK_GROUND);
	}

void Game::UpdateScreen() {
	WriteConsoleOutput(m_hConsole, m_bufScreen, m_bufferSize, m_bufferCoord, &m_rectWindow);
	}

void Game::RainbowFill() {
	for (size_t i = 0; i < ScreenWidth(); i++) {
		for (size_t j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, (i + j) % 255);
		}
	}
}

void Game::WaitKey(int vKey) {
	while ((0x8000 & GetAsyncKeyState(vKey)) == 0);
}

void Game::DrawBorder() {
	int x = 0;
	int y = 0;

	for (int d = 0; d < 4; d++) {
		while (x >= 0 && x < ScreenWidth() && y >= 0 && y < ScreenHeight()) {
			Draw(x, y, PIXEL_BLANK, BORDER);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}