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
	void DrawBorder();
	void ClearScreen();

private:
	unsigned int score;
	Car m_car;
	bool exit;
};