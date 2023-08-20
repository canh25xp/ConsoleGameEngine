#include "Game.h"

Game::Game() {
	m_sAppName = L"Racing";
	m_border = nullptr;
	m_car = nullptr;
}

bool Game::OnUserCreate() {
	m_border = new myGame::Rectangle(4, 4, ScreenWidth() - 4, ScreenHeight() - 4);
	m_car = new Car();
	m_car->LoadSprite(L"assets/car1.spr");
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	//if(m_keys[VK_UP].bPressed){
	//	m_car.position.MoveUp(m_car.spr->nHeight);
	//	Clip(m_car.position.x, m_car.position.y);
	//}

	if(m_keys[VK_RIGHT].bPressed){
		m_car->position.MoveRight(m_car->spr->nWidth);
		Clip(m_car->position.x, m_car->position.y);
	}

	//if(m_keys[VK_DOWN].bPressed){
	//	m_car.position.MoveDown(m_car.spr->nHeight);
	//	Clip(m_car.position.x, m_car.position.y);
	//}

	if(m_keys[VK_LEFT].bPressed){
		m_car->position.MoveLeft(m_car->spr->nWidth);
		Clip(m_car->position.x, m_car->position.y);
	}

	ClearScreen();
	DrawBorder();

	DrawSprite(m_car->position.x, m_car->position.y, m_car->spr);
	return true;
}

void Game::ClearScreen() {
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_BLANK, BACK_GROUND);
}

void Game::UpdateScreen() {
	WriteConsoleOutput(m_hConsole, m_bufScreen, m_bufferSize, m_bufferCoord, &m_rectWindow);
}

void Game::RainbowFill() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, (i + j) % 255);
		}
	}
}

void Game::WaitKey(int vKey) {
	while ((0x8000 & GetAsyncKeyState(vKey)) == 0);
}

void Game::DrawBorder() {
	int x = m_border->x;
	int y = m_border->y;

	for (int d = 0; d < 4; d++) {
		while (x >= m_border->x && x < m_border->width && y >= m_border->y && y < m_border->height) {
			Draw(x, y, PIXEL_BLANK, BORDER);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}