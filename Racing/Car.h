#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

class Car {
public:
	Car();
	~Car();

public:
	void LoadSprite(std::wstring sFile = L"assets/car1.spr");

public:
	myGame::Point position;	//top_left of the car
	Sprite* spr;
};