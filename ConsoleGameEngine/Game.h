#pragma once

#include <iostream>
#include "ConsoleGameEngine.h"

class Game : public cge::ConsoleGameEngine {
public:
	Game();
public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
public:
	unsigned int score;
};
