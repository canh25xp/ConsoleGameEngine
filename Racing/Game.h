#pragma once
#include "ConsoleGameEngine.h"
#include "Car.h"
#include "font.h"

const int MAX_NPC = 5;

const COLOUR BACK_GROUND = BG_BLACK;
const COLOUR BORDER = BG_DARK_RED;

const int BORDER_WIDTH = 120;
const int BORDER_HEIGHT = 160;

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
	void InitPlayer();

	int score;

private:
	Rect* pBorder;
	Car* pPlayer;
	//Car* pPlayer2;
	Car* m_npc[MAX_NPC];
	Font* pFont;

	//Sprite* pMap[4];

private:
	float interval;
	float timeSinceStart;
	int hitSoundEffect;
};