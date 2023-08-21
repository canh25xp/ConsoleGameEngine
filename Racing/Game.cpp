#include "Game.h"

using namespace std::chrono;

Game::Game() {
	m_sAppName	= L"Racing";
	m_border	= nullptr;
	m_car		= nullptr;
	for (int i = 0; i < 3; i++){
		m_obstacles[i] = nullptr;
	}
	m_duration = 0;
}

bool Game::OnUserCreate() {
	//start = system_clock::now();
	//DrawGrid();
	//UpdateScreen();
	//WaitKey(VK_SPACE);
	//m_car		= new Car();
	m_car = new Car(L"assets/car1.spr");

	for (int i = 0; i < 3; i++){
		m_obstacles[i] = new Car(L"assets/car2.spr");
	}

	m_border = new Rect(BORDER_OFFSET, BORDER_OFFSET, ScreenWidth() - BORDER_OFFSET*2, ScreenHeight() - BORDER_OFFSET*2);

	m_car->SetPosition(m_border->Left() + m_car->Width() + 10, m_border->Bottom() - m_car->Height() - 10);

	for (int i = 0; i < 3; i++){
		m_obstacles[i]->RandomizePositionX(*m_border); 
	}

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	ClearScreen();

	m_duration += fElapsedTime;
	//if (m_keys[VK_UP].bHeld) {
	//	m_car->MoveUp(1);
	//}

	//if (m_keys[VK_DOWN].bHeld) {
	//	m_car->MoveDown(1);
	//}

	if(m_keys[VK_RIGHT].bHeld){
		m_car->MoveRight(1);
	}

	if(m_keys[VK_LEFT].bHeld){
		m_car->MoveLeft(1);
	}

	if(m_duration > 0.01){
		m_obstacles[0]->MoveDown(1);
		m_duration = 0;
	}

	//wchar_t string[256];
	//swprintf_s(string, 256, L"Duration = %f", m_duration);
	//DrawString(0, 0, string, BG_WHITE);


	m_car->ClipToTight(*m_border, 1);


	m_border->DrawSelf(this);
	m_car->DrawSelf(this);
	
	m_obstacles[0]->DrawSelf(this);

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
	COORD bufferCoord;
	COORD bufferSize;
	bufferSize.X = (short) m_nScreenWidth;
	bufferSize.Y = (short) m_nScreenHeight;
	bufferCoord.X = 0;
	bufferCoord.Y = 0;
	WriteConsoleOutput(m_hConsole, m_bufScreen, bufferSize, bufferCoord, &m_rectWindow);
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