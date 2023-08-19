#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

class Car {
public:
	Car();
	~Car();
public:
	void DrawSelf(ConsoleGameEngine* grf);

private:
	int width;
	int height;
public:
	Point2D position;	//top_left of the car
	Sprite* spr;
};