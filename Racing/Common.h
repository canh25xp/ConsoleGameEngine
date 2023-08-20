#pragma once
#include "ConsoleGameEngine.h"

const COLOUR BACK_GROUND = BG_BLACK;
const COLOUR BORDER		 = BG_DARK_RED;

//Right, Down, Left, Up
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

const int BORDER_OFFSET = 20;

class Point {
public:
	int x;
	int y;

public:
	Point();
	Point(int _x, int _y);

public:
	void MoveRight(int distance = 1);
	void MoveDown(int distance = 1);
	void MoveLeft(int distance = 1);
	void MoveUp(int distance = 1);
};

class Rect : public Point {
public:
	int width;
	int height;

public:
	Rect();
	Rect(int x, int y, int width, int height);
	~Rect();

public:
	int Top() const;
	int Bottom() const;
	int Left() const;
	int Right() const;

	Point TopLeft() const;
	Point TopRight() const;
	Point BottomLeft() const;
	Point BottomRight() const;

	void ClipTo(const Rect& boundary);
	void ClipTo(const Rect& boundary, int offset);
	void ClipToTight(const Rect& boundary);
	void ClipToTight(const Rect& boundary, int offset);
};