#pragma once
#include "ConsoleGameEngine.h"
#include "Car.h"
#include "Common.h"

#define OBSTACLES_COUNT 3

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
	void MarkDanger(const Car& obstacle);
	void InitPlayer();
	void InitObstacles();

private:
	Rect *m_border;
	Car *m_player;
	Car *m_obstacles[OBSTACLES_COUNT];
	Sprite *m_shareSpr;
	
	int m_playerY;

private:
	float m_count;
};