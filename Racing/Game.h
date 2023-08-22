#pragma once
#include "ConsoleGameEngine.h"
#include "Car.h"

const int MAX_NPC = 4;

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

private:
	Rect* m_border;
	Car* m_player;
	Car* m_npc[MAX_NPC];

private:
	float m_count;
};