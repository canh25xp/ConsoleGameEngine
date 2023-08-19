#pragma once
#include "ConsoleGameEngine.h"

struct Point2D{
	int x;
	int y;
	Point2D();
	Point2D(int _x, int _y);
};

class Car{
public:
	Car();
	~Car();
public:
	void DrawSelf(ConsoleGameEngine* grf);
	void Up();
	void Right();
	void Down();
	void Left();

private:
	Point2D position;	//top_left of the car
	int width;
	int height;
public:
	Sprite* spr_car;
};