#include "Game.h"

using namespace std::chrono;

Game::Game() {
	m_sAppName = L"Racing";
	pBorder = nullptr;
	pPlayer = nullptr;

	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = nullptr;

	pFont = nullptr;

	interval = 0;
	timeSinceStart = 0;
	hitSoundEffect = 0;
	score = 0;

	EnableSound();
}

bool Game::OnUserCreate() {
	//pMap[0] = new Sprite(L"assets/map1x1.spr");
	//pMap[1] = new Sprite(L"assets/map1x2.spr");
	//pMap[2] = new Sprite(L"assets/map2x1.spr");
	//pMap[3] = new Sprite(L"assets/map2x2.spr");



	pBorder = new Rect(0, 0, BORDER_WIDTH, BORDER_HEIGHT);

	//Load player sprite
	pPlayer = new Car(L"assets/car4.spr");
	//pPlayer2 = new Car(L"assets/car2.spr");

	//Load NPC sprite
	for (int i = 0; i < MAX_NPC; i++)
		m_npc[i] = new Car(L"assets/car2.spr");

	pFont = new Font(L"fontSmall");

	pFont->LoadFont();

	//Randomize NPC's X coordinate, restricted by the border
	for (int i = 0; i < MAX_NPC; i++) {
		m_npc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - m_npc[i]->Width());
		m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
	}

	hitSoundEffect = LoadAudioSample(L"assets/vine_boom.wav");

	InitPlayer();
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	ClearScreen();

	//DrawSprite(0,0, pMap[0]);
	//DrawSprite(60,0, pMap[1]);
	//DrawSprite(0,80, pMap[2]);
	//DrawSprite(60,80, pMap[3]);

	//int k = 0;
	//Fill(0,0,2,159, PIXEL_SOLID, FG_WHITE);
	//Fill(118,0,120,159, PIXEL_SOLID, FG_WHITE);
	//for(int i = 0; i <= 1; i++){
	//	for (int j = 0; j < BORDER_HEIGHT; j++){
	//		if (j % 8 >= k && j % 8 <= k + 3){
	//			Draw(59 + i, j, PIXEL_SOLID, FG_DARK_YELLOW);
	//		}
	//	}
	//}
	//if (k == 4) k = 0;
	//k++;

	

	pFont->Print(this, "SCORE", BORDER_WIDTH + 10, BORDER_HEIGHT / 2);
	//pFont->Print(this, 1, 0, 0);

	timeSinceStart += fElapsedTime;
	interval += fElapsedTime;

	if(timeSinceStart > 0.001)
		score++;

	//if (m_keys['A'].bHeld) {
	//	pPlayer2->MoveLeft(1);
	//}

	//if (m_keys['D'].bHeld) {
	//	pPlayer2->MoveRight(1);
	//}

	if (m_keys[VK_RIGHT].bHeld) {
		pPlayer->MoveRight(1);
	}

	if (m_keys[VK_LEFT].bHeld) {
		pPlayer->MoveLeft(1);
	}

	if (interval > 0.0005) {
		for (int i = 0; i < MAX_NPC; i++) {
			m_npc[i]->MoveDown(1);
		}
		interval = 0;
	}

	pPlayer->ClipToTight(*pBorder, 2);
	//pPlayer2->ClipToTight(*pBorder, 2);

	for (int i = 0; i < MAX_NPC; i++) {
		if (pPlayer->CollisionWith(*m_npc[i])) {
			PlaySample(hitSoundEffect);
			WaitKey(VK_SPACE);
			InitPlayer();
			for (int i = 0; i < MAX_NPC; i++) {
				m_npc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - m_npc[i]->Width());
				m_npc[i]->SetY(0 - ((BORDER_HEIGHT / MAX_NPC) * i));
			}
		}
	}

	pPlayer->DrawSelf(this);
	//pPlayer2->DrawSelf(this);

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

	////DrawBorder();

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
	//pPlayer2->SetPosition(80, pBorder->Bottom() - 2 * pPlayer->Height());

}