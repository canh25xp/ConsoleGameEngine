#pragma once
#include "ConsoleGameEngine.h"

//Right, Down, Left, Up
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

class Point {
public:
	Point();
	Point(int x, int y);

protected:
	int x;
	int y;

public:
	void MoveRight(int distance = 1);
	void MoveDown(int distance = 1);
	void MoveLeft(int distance = 1);
	void MoveUp(int distance = 1);

	void SetPosition(int x, int y);
	void SetX(int x);
	void SetY(int y);

	void RandomizeX(int min, int max);
	void RandomizeY(int min, int max);

	int GetX() const;
	int GetY() const;
};
