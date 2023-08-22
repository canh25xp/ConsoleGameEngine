#include "Game.h"

using namespace std::chrono;

Game::Game() {
	m_sAppName = L"Racing";
	m_border = nullptr;
	m_player = nullptr;

	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = nullptr;

	m_count = 0;

	//HideFPS();
}

bool Game::OnUserCreate() {
	m_border = new Rect(0, 0, BORDER_WIDTH, BORDER_HEIGHT);

	//Load player sprite
	m_player = new Car(L"assets/car1.spr");

	//Load NPC sprite
	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = new Car(L"assets/car2.spr");

	//Randomize NPC's X coordinate, restricted by the border
	for (int i = 0; i < MAX_NPC; i++) {
		m_npc[i]->RandomizeX(m_border->Left(), m_border->Right() - m_npc[i]->Width());
		m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
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

	if (m_keys[VK_RIGHT].bHeld) {
		m_player->MoveRight(1);
	}

	if (m_keys[VK_LEFT].bHeld) {
		m_player->MoveLeft(1);
	}

	if (m_count > 0.005) {
		for (int i = 0; i < MAX_NPC; i++) {
			m_npc[i]->MoveDown(1);
		}
		m_count = 0;
	}

	m_player->ClipToTight(*m_border, 1);

	for (int i = 0; i < MAX_NPC; i++) {
		if (m_player->CollisionWith(*m_npc[i])) {
			WaitKey(VK_SPACE);
			InitPlayer();
			for (int i = 0; i < MAX_NPC; i++) {
				m_npc[i]->RandomizeX(m_border->Left(), m_border->Right() - m_npc[i]->Width());
				m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
			}
		}
	}

	m_player->DrawSelf(this);

	for (int i = 0; i < MAX_NPC; i++) {
		m_npc[i]->DrawSelf(this);
	}


	for (int i = 0; i < MAX_NPC; i++) {
		if (m_npc[i]->OutOfBound(*m_border)) {
			m_npc[i]->RandomizeX(m_border->Left(), m_border->Right() - m_npc[i]->Width());
			m_npc[i]->SetY(-50);
		}
	}

	m_border->DrawSelf(this, PIXEL_BLANK, BG_DARK_RED);
	//DrawBorder();

	return true;
}

bool Game::OnUserDestroy() {
	delete m_border;
	delete m_player;
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

void Game::DrawBorder() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			if (j <= m_border->Top() || j >= m_border->Bottom() || i <= m_border->Left() || i >= m_border->Right())
				Draw(i, j, PIXEL_BLANK, BORDER);
		}
	}
}

void Game::InitPlayer() {
	m_player->SetPosition(60, m_border->Bottom() - 2 * m_player->Height());
}

