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

	if(m_keys[VK_RIGHT].bPressed){
		m_car.position.MoveRight(4);
	}

	if(m_keys[VK_DOWN].bPressed){
		m_car.position.MoveDown(4);
	}

	if(m_keys[VK_LEFT].bPressed){
		m_car.position.MoveLeft(4);
	}

	ClearScreen();
	//wchar_t messeage[256];
	//swprintf_s(messeage, 256, L"Elapse Time = %f", fElapsedTime);
	//DrawString(30, 30, messeage);
	DrawBorder();
	m_car.DrawSelf(this);
	return true;
}

void Game::ClearScreen(){
	Fill(0,0 , ScreenWidth(), ScreenHeight(), PIXEL_BLANK, BACK_GROUND);
}

void Game::DrawBorder(){
	int x=0;
	int y=0;

	for (int d = 0; d < 4; d++){
		while(x >= 0 && x < ScreenWidth() && y >= 0 && y < ScreenHeight()){
			Draw(x, y, PIXEL_BLANK, BORDER);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}