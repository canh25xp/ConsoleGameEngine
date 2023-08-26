#pragma once
#include "ConsoleGameEngine.h"
#include "Car.h"
#include "font.h"

// define 1 to enable multi-player, define zero to disable
#define MULTI_PLAYER 0

// numbers of NPC to be render at the same time
const int NPC = 4;

const COLOUR BACK_GROUND	= BG_BLACK;
const COLOUR BORDER			= BG_DARK_RED;

const int SCREEN_WIDTH		= 200;
const int SCREEN_HEIGHT		= 160;
const int PIXEL_SIZE		= 4;

const int BORDER_X			= 0;
const int BORDER_Y			= 0;
const int BORDER_WIDTH		= 100;
const int BORDER_HEIGHT		= 160;

const int MENU_X			= BORDER_WIDTH;
const int MENU_Y			= 0;
const int MENU_WIDTH		= SCREEN_WIDTH - BORDER_WIDTH;
const int MENU_HEIGHT		= SCREEN_HEIGHT;

class Game : public ConsoleGameEngine {
public:
	Game();

protected:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

public:
	void ClearScreen();
	void UpdateScreen();
	void FillRainbow();
	void WaitKey(int vKey);
	void FillGrid();
	void DrawBorder();

	void Spawn(Car* car);

private:
	Rect* pBorder;

	Car* pPlayer_1;

#if MULTI_PLAYER
	Car* pPlayer_2;
#endif

	Car* pNpc[NPC];

	Font* pFont;
	Font* pTitleFont;

private:
	int score;
	int speed;
	float interval;
	float delay;
	float timeSinceStart;
	int hitSoundEffect;

	bool gameOver;
};