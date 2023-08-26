#include "Game.h"

Game::Game() {
	m_sAppName = L"Racing Console Game";

	pBorder = nullptr;

	pPlayer = nullptr;

	for (int i = 0; i < NPC; i++)
		pNpc[i] = nullptr;

	pFont = nullptr;

	speed = 0;
	interval = 0;
	delay = 0;
	timeSinceStart = 0;
	hitSoundEffect = 0;
	score = 0;
	highScore = 0;

	EnableSound();
}

bool Game::OnUserCreate() {
	// Instantiate border
	pBorder = new Rect(BORDER_X, BORDER_Y, BORDER_WIDTH, BORDER_HEIGHT);

	// Load players sprite
	pPlayer = new Car(L"assets/cars/car2.spr");

	//Load NPCs sprite
	for (int i = 0; i < NPC; i++)
		pNpc[i] = new Car(L"assets/cars/car1.spr");


	// Load Fonts Sprites
	pFont = new Font(L"assets/fontSmall");
	pTitleFont = new Font(L"assets/font");

	//Randomize NPC's X coordinate, restricted by the border
	for (int i = 0; i < NPC; i++) {
		pNpc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - pNpc[i]->Width());
		pNpc[i]->SetY(0 - ((pBorder->Height() / NPC) * i));
	}

	hitSoundEffect = LoadAudioSample(L"assets/soundFX/vine_boom.wav");

	pPlayer->SetPosition(60, pBorder->Bottom() - 2 * pPlayer->Height());

	delay = 0.005f;
	speed = 1;
	gameOver = false;

	//TitleScreen();
	//WaitKey(VK_SPACE);

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {
	ClearScreen();

	timeSinceStart += fElapsedTime;
	interval += fElapsedTime;

	//pFont->DrawString(this, "RUN TIME ", MENU_X + 10, 0);
	//pFont->DrawString(this, std::to_string(timeSinceStart), pFont->GetLastPosition());

	pFont->DrawString(this, "YOUR SCORE ", MENU_X + 10, 30);
	pFont->DrawString(this, std::to_string(score), pFont->GetLastPosition());

	pFont->DrawString(this, "HIGH SCORE ", MENU_X + 10, 50);
	pFont->DrawString(this, std::to_string(highScore), pFont->GetLastPosition());

	if (m_keys[VK_UP].bPressed) {
		if(speed < 4)
			speed++;
	}

	if (m_keys[VK_DOWN].bPressed) {
		if(speed > 1)
			speed--;
	}

	if(m_keys['W'].bHeld){
		pPlayer->MoveUp(speed);
		
	}

	if(m_keys['S'].bHeld){
		pPlayer->MoveDown(speed);
	}

	if (m_keys[VK_RIGHT].bHeld) {
		pPlayer->MoveRight(speed);
	}

	if (m_keys[VK_LEFT].bHeld) {
		pPlayer->MoveLeft(speed);
	}

	if (interval > delay) {
		//DrawLine();
		for (int i = 0; i < NPC; i++) {
			pNpc[i]->MoveDown(speed);
		}
		score++;
		interval = 0;
	}

	pPlayer->ClipToTight(*pBorder, 1);

	for (int i = 0; i < NPC; i++) {
		if (pPlayer->CollisionWith(*pNpc[i])) {
			PlaySample(hitSoundEffect);
			WaitKey(VK_SPACE);
			Spawn(pPlayer);
			if(score > highScore)
				highScore = score;

			score = 0;
			speed = 1;

			for (int i = 0; i < NPC; i++) {
				pNpc[i]->RandomizeX(pBorder->Left(), pBorder->Right() - pNpc[i]->Width());
				pNpc[i]->SetY(0 - ((BORDER_HEIGHT / NPC) * i));
			}
		}
	}

	pPlayer->DrawSelf(this);

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
	delete pPlayer;

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
	car->SetPosition(60, pBorder->Bottom() - 2 * pPlayer->Height());
}

void Game::DrawLine(){
	static int k = 0;

	for(int i = 0; i <= 1; i++){
		for (int j = 0; j < BORDER_HEIGHT; j++){
			if (j % 16 >= 0 && j % 16 <= 8){
				Draw(BORDER_WIDTH/2 - 1 + i, j+k, PIXEL_SOLID, FG_DARK_YELLOW);
			}
		}
	}

	k++;
	if (k == 8) k = 0;
}

void Game::TitleScreen(){
	//FillRainbow();
	pTitleFont->DrawString(this, "RACING GAME", 30, SCREEN_HEIGHT / 2);
	UpdateScreen();
}
