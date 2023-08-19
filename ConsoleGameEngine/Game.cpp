#include "Game.h"

Game::Game() {
	m_sAppName = L"Racing";
}

bool Game::OnUserCreate() {
	score = 0;
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	if(m_keys[VK_UP].bPressed){
		m_car.Up();
	}

	if(m_keys[VK_RIGHT].bPressed){
		m_car.Right();
	}

	if(m_keys[VK_DOWN].bPressed){
		m_car.Down();
	}

	if(m_keys[VK_LEFT].bPressed){
		m_car.Left();
	}
	ClearScreen();
	//DrawBorder();
	m_car.DrawSelf(this);
	return true;
}

void Game::ClearScreen(){
	Fill(0,0 , ScreenWidth(), ScreenHeight(), ' ', cge::BG_BLACK);
}

void Game::DrawBorder(){
	const int dx[]={1,0,-1,0};
	const int dy[]={0,1,0,-1};

	int x=0;
	int y=0;

	for (int d = 0; d < 4; d++){
		while(x >= 0 && x < ScreenWidth() && y >= 0 && y < ScreenHeight()){
			Draw(x, y, ' ', cge::BG_DARK_RED);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}