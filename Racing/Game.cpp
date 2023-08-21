#include "Game.h"

Game::Game() {
	m_sAppName	= L"Racing";
	m_border	= nullptr;
	m_car		= nullptr;
}

bool Game::OnUserCreate() {
	//DrawGrid();
	//UpdateScreen();
	//WaitKey(VK_SPACE);
	m_car		= new Car();
	//m_car = new Car(L"assets/car1.spr");

	m_border	= new Rect(BORDER_OFFSET, BORDER_OFFSET, ScreenWidth() - BORDER_OFFSET*2, ScreenHeight() - BORDER_OFFSET*2);

	//int btop = m_border->Top();
	//int bbottom = m_border->Bottom();
	//int bleft = m_border->Left();
	//int bright = m_border->Right();

	//int ctop = m_car->Top();
	//int cbottom = m_car->Bottom();
	//int cleft = m_car->Left();
	//int cright =m_car->Right();


	//m_car->SetPosition(m_border->Left() + m_car->getWidth() + 10, m_border->Bottom() - m_car->getHeight() - 10);

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	if (m_keys[VK_UP].bPressed) {
		m_car->MoveUp(m_car->getHeight());
	}

	if (m_keys[VK_DOWN].bPressed) {
		m_car->MoveDown(m_car->getHeight());
	}

	if(m_keys[VK_RIGHT].bPressed){
		m_car->MoveRight(m_car->getWidth());
	}

	if(m_keys[VK_LEFT].bPressed){
		m_car->MoveLeft(m_car->getWidth());
	}

	m_car->ClipTo(*m_border);

	ClearScreen();

	m_border->drawSelf(this);
	m_car->drawSelf(this);

	return true;
}

bool Game::OnUserDestroy() {
	delete m_border;
	delete m_car;
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

void Game::DrawGrid() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, ((i + j) % 2) ? COLOUR::BG_BLACK : COLOUR::BG_WHITE);
		}
	}
}