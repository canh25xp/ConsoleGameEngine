#include "Game.h"

Game::Game() {
	m_sAppName = L"Racing";

	pBorder = nullptr;

	pPlayer_1 = nullptr;

#if MULTI_PLAYER
	pPlayer_2 = nullptr;
#endif // MULTI_PLAYER

	for (int i = 0; i < NPC; i++)
		pNpc[i] = nullptr;

	pFont = nullptr;

	speed = 0;
	interval = 0;
	delay = 0;
	timeSinceStart = 0;
	hitSoundEffect = 0;
	score = 0;
	gameOver = false;

	EnableSound();
}

bool Game::OnUserCreate() {
	// Instantiate border
	pBorder = new Rect(BORDER_X, BORDER_Y, BORDER_WIDTH, BORDER_HEIGHT);

	// Load players sprite
	pPlayer_1 = new Car(L"assets/car4.spr");

#if MULTI_PLAYER
	pPlayer_2 = new Car(L"assets/car2.spr");
#endif

	//Load NPCs sprite
	for (int i = 0; i < NPC; i++)
		pNpc[i] = new Car(L"assets/car2.spr");

	pFont = new Font(L"fontSmall");
	pTitleFont = new Font(L"font");

	//Randomize NPC's X coordinate, restricted by the border
	for (int i = 0; i < NPC; i++) {
		pNpc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - pNpc[i]->Width());
		pNpc[i]->SetY(0 - ((BORDER_HEIGHT / NPC) * i));
	}

	hitSoundEffect = LoadAudioSample(L"assets/vine_boom.wav");

	pPlayer_1->SetPosition(60, pBorder->Bottom() - 2 * pPlayer_1->Height());

#if MULTI_PLAYER
	pPlayer_2->SetPosition(60, pBorder->Bottom() - 2 * pPlayer_2->Height());
#endif

	delay = 0.001;
	speed = 1;

	pTitleFont->DrawString(this, "RACING GAME", 30, SCREEN_HEIGHT / 2);
	UpdateScreen();

	WaitKey(VK_SPACE);

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	ClearScreen();

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


	timeSinceStart += fElapsedTime;
	interval += fElapsedTime;

	if(timeSinceStart > 0.01)
		score++;

	pFont->DrawString(this, "YOUR SCORE ", MENU_X + 10, MENU_HEIGHT/ 2);
	pFont->DrawString(this, std::to_string(score), pFont->GetLastPosition());

#if MULTI_PLAYER
	if (m_keys['A'].bHeld) {
		pPlayer_2->MoveLeft(1);
	}

	if (m_keys['D'].bHeld) {
		pPlayer_2->MoveRight(1);
	}
#endif

	if (m_keys[VK_UP].bPressed) {
		while(speed < 4)
			speed++;
	}

	if (m_keys[VK_DOWN].bPressed) {
		while(speed > 1)
			speed--;
	}

	if (m_keys[VK_RIGHT].bHeld) {
		pPlayer_1->MoveRight(speed);
	}

	if (m_keys[VK_LEFT].bHeld) {
		pPlayer_1->MoveLeft(speed);
	}

	if (interval > delay) {
		for (int i = 0; i < NPC; i++) {
			pNpc[i]->MoveDown(speed);
		}
		interval = 0;
	}

	pPlayer_1->ClipToTight(*pBorder, 2);

#if MULTI_PLAYER
	pPlayer_2->ClipToTight(*pBorder, 2);
#endif

	for (int i = 0; i < NPC; i++) {
		if (pPlayer_1->CollisionWith(*pNpc[i])) {
			PlaySample(hitSoundEffect);
			WaitKey(VK_SPACE);
			Spawn(pPlayer_1);
			for (int i = 0; i < NPC; i++) {
				pNpc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - pNpc[i]->Width());
				pNpc[i]->SetY(0 - ((BORDER_HEIGHT / NPC) * i));
			}
		}
	}

	pPlayer_1->DrawSelf(this);

#if MULTI_PLAYER
	pPlayer_2->DrawSelf(this);
#endif

	for (int i = 0; i < NPC; i++) {
		pNpc[i]->DrawSelf(this);
	}

	for (int i = 0; i < NPC; i++) {
		if (pNpc[i]->OutOfBound(*pBorder)) {
			pNpc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - pNpc[i]->Width());
			pNpc[i]->SetY(-50);
		}
	}

	pBorder->DrawSelf(this, PIXEL_BLANK, BG_DARK_RED);

	////DrawBorder();

	return true;
}

bool Game::OnUserDestroy() {
	delete pBorder;
	delete pPlayer_1;

#if MULTI_PLAYER
	delete pPlayer_2;
#endif

	delete pFont;
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

void Game::Spawn(Car* car) {
	car->SetPosition(60, pBorder->Bottom() - 2 * pPlayer_1->Height());
}
