#pragma once
#include <iostream>
#include "ConsoleGameEngine.h"
#include "Car.h"

class Game : public cge::ConsoleGameEngine {
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
};