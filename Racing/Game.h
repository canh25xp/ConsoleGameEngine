#pragma once
#include <iostream>
#include "ConsoleGameEngine.h"
#include "Car.h"
#include "Common.h"

class Game : public ConsoleGameEngine {
public:
	Game();
protected:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

public:
	void DrawBorder();
	void ClearScreen();
	void UpdateScreen();
	void RainbowFill();
	void WaitKey(int vKey);
private:
	myGame::Rectangle* m_border;
	Car* m_car;
};