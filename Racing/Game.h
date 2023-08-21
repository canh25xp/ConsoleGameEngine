#pragma once
#include "ConsoleGameEngine.h"
#include "Car.h"
#include "Common.h"

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
	void RainbowFill();
	void WaitKey(int vKey);
	void DrawGrid();

private:
	Rect* m_border;
	Car* m_car;
	Car* m_obstacles[3];

	float m_duration;
};