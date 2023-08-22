#include "Game.h"

using namespace std::chrono;

Game::Game() {
	m_sAppName = L"Racing";
	pBorder = nullptr;
	pPlayer = nullptr;

	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = nullptr;

	interval = 0;
	timeSinceStart = 0;
	hitSoundEffect = 0;

	//EnableSound();

	//HideFPS();
}

bool Game::OnUserCreate() {
	pBorder = new Rect(0, 0, BORDER_WIDTH, BORDER_HEIGHT);

	//Load player sprite
	pPlayer = new Car(L"assets/car1.spr");

	//Load NPC sprite
	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = new Car(L"assets/car2.spr");

	//Randomize NPC's X coordinate, restricted by the border
	for (int i = 0; i < MAX_NPC; i++) {
		m_npc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - m_npc[i]->Width());
		m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
	}

	//hitSoundEffect = LoadAudioSample(L"assets/vine_boom.wav");

	InitPlayer();
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	//if(m_keys[VK_SPACE].bPressed)
	//	PlaySample(hitSoundEffect);

	ClearScreen();
	timeSinceStart += fElapsedTime;
	interval += fElapsedTime;

	//if (m_keys[VK_UP].bHeld) {
	//	pPlayer->MoveUp(1);
	//}

	//if (m_keys[VK_DOWN].bHeld) {
	//	pPlayer->MoveDown(1);
	//}

	if (m_keys[VK_RIGHT].bHeld) {
		pPlayer->MoveRight(1);
	}

	if (m_keys[VK_LEFT].bHeld) {
		pPlayer->MoveLeft(1);
	}

	if (interval > 0.005) {
		for (int i = 0; i < MAX_NPC; i++) {
			m_npc[i]->MoveDown(1);
		}
		interval = 0;
	}

	pPlayer->ClipToTight(*pBorder, 1);

	for (int i = 0; i < MAX_NPC; i++) {
		if (pPlayer->CollisionWith(*m_npc[i])) {
			WaitKey(VK_SPACE);
			InitPlayer();
			for (int i = 0; i < MAX_NPC; i++) {
				m_npc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - m_npc[i]->Width());
				m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
			}
		}
	}

	pPlayer->DrawSelf(this);

	for (int i = 0; i < MAX_NPC; i++) {
		m_npc[i]->DrawSelf(this);
	}


	for (int i = 0; i < MAX_NPC; i++) {
		if (m_npc[i]->OutOfBound(*pBorder)) {
			m_npc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - m_npc[i]->Width());
			m_npc[i]->SetY(-50);
		}
	}

	pBorder->DrawSelf(this, PIXEL_BLANK, BG_DARK_RED);
	//DrawBorder();

	return true;
}

bool Game::OnUserDestroy() {
	delete pBorder;
	delete pPlayer;
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
			if (j <= pBorder->Top() || j >= pBorder->Bottom() || i <= pBorder->Left() || i >= pBorder->Right())
				Draw(i, j, PIXEL_BLANK, BORDER);
		}
	}
}

void Game::InitPlayer() {
	pPlayer->SetPosition(60, pBorder->Bottom() - 2 * pPlayer->Height());
}

