#include "Game.h"

using namespace std::chrono;

Game::Game() {
	m_sAppName	= L"Racing";
	m_border	= nullptr;
	m_player		= nullptr;
	for (int i = 0; i < OBSTACLES_COUNT; i++)
		m_obstacles[i] = nullptr;

	//HideFPS();
}

bool Game::OnUserCreate() {
	m_count = 0;

	m_border = new Rect(0, 0, 120, 160);
	m_player = new Car(L"assets/car1.spr");
	m_shareSpr = new Sprite(L"assets/car2.spr");

	for (int i = 0; i < OBSTACLES_COUNT; i++){
		m_obstacles[i] = new Car();
	}

	for (int i = 0; i < OBSTACLES_COUNT; i++){
		m_obstacles[i]->LoadSprite(m_shareSpr);
	}

	for (int i = 0; i < OBSTACLES_COUNT; i++){
		m_obstacles[i]->RandomizeX(*m_border); 
	}

	for (int i = 0; i < OBSTACLES_COUNT; i++){

	}

	InitPlayer();
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	ClearScreen();

	m_count += fElapsedTime;
	//if (m_keys[VK_UP].bHeld) {
	//	m_player->MoveUp(1);
	//}

	//if (m_keys[VK_DOWN].bHeld) {
	//	m_player->MoveDown(1);
	//}

	if(m_keys[VK_RIGHT].bHeld){
		m_player->MoveRight(1);
	}

	if(m_keys[VK_LEFT].bHeld){
		m_player->MoveLeft(1);
	}

	if(m_count > 0.001){
		for (int i = 0; i < OBSTACLES_COUNT; i++){
			m_obstacles[i]->MoveDown(1);

		}
		m_count = 0;
	}

	m_player->ClipToTight(*m_border, 1);

	//for (int i = 0; i < OBSTACLES_COUNT; i++){
	//	if(m_player->CollisionWith(*m_obstacles[i])){
	//		m_player->SetPositionBottomLeft(60, m_border->Bottom()-10);
	//		WaitKey(VK_SPACE);
	//		m_obstacles[i]->SetPositionBottomLeft(0,m_border->Top() - 50);
	//		m_obstacles[i]->RandomizePositionX(*m_border);
	//	}
	//}

	m_player->DrawSelf(this);

	for (int i = 0; i < OBSTACLES_COUNT; i++){
		m_obstacles[i]->DrawSelf(this);
	}


	for (int i = 0; i < OBSTACLES_COUNT; i++){
		if(m_obstacles[i]->OutOfBound(*m_border)){
			m_obstacles[i]->SetPosition(0,m_border->Top() - i*50);
			m_obstacles[i]->RandomizeX(*m_border); 
		}
	}

	m_border->DrawSelf(this);
	//DrawBorder();

	return true;
}

bool Game::OnUserDestroy() {
	delete m_border;
	delete m_player;
	delete m_shareSpr;
	return true;
}

void Game::ClearScreen() {
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_BLANK, BACK_GROUND);
}

void Game::UpdateScreen() {
	COORD bufferCoord;
	COORD bufferSize;
	bufferSize.X = (short) m_nScreenWidth;
	bufferSize.Y = (short) m_nScreenHeight;
	bufferCoord.X = 0;
	bufferCoord.Y = 0;
	WriteConsoleOutput(m_hConsole, m_bufScreen, bufferSize, bufferCoord, &m_rectWindow);
}

void Game::FillRainbow() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, (i + j) % 255);
		}
	}
}

void Game::WaitKey(int vKey) {
	while ((0x8000 & GetAsyncKeyState(vKey)) == 0);
}

void Game::FillGrid() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, ((i + j) % 2) ? COLOUR::BG_BLACK : COLOUR::BG_WHITE);
		}
	}
}

void Game::DrawBorder(){
	for (int i = 0; i < ScreenWidth(); i++){
		for (int j = 0; j < ScreenHeight(); j++){
			if(j <= m_border->Top() || j >= m_border->Bottom() || i <= m_border->Left() || i>= m_border->Right())
				Draw(i, j, PIXEL_BLANK, BORDER);
		}
	}
}

void Game::InitPlayer(){
	m_player->SetPosition(60, m_border->Bottom() - 2*m_player->Height());
}

