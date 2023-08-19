#pragma once
#include "ConsoleGameEngine.h"

const COLOUR BACK_GROUND = BG_DARK_GREY;
const COLOUR BORDER		 = BG_DARK_RED;

const COLOUR CAR_TIRE	 = BG_BLACK;
const COLOUR CAR_MAIN    = BG_BLUE;
const COLOUR CAR_AXIAL   = BG_GREY;
const COLOUR CAR_WINDOW  = BG_WHITE;

//Right, Down, Left, Up
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

struct Point2D {
	int x;
	int y;
	Point2D();
	Point2D(int _x, int _y);

	void MoveRight	(int distance = 1);
	void MoveDown	(int distance = 1);
	void MoveLeft	(int distance = 1);
	void MoveUp		(int distance = 1);
};
