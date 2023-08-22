#pragma once
#include "ConsoleGameEngine.h"

const COLOUR BACK_GROUND = BG_BLACK;
const COLOUR BORDER		 = BG_DARK_RED;

//Right, Down, Left, Up
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

class Point {
public:
	Point();
	Point(int _x, int _y);

protected:
	int x;
	int y;

public:
	void MoveRight(int distance = 1);
	void MoveDown(int distance = 1);
	void MoveLeft(int distance = 1);
	void MoveUp(int distance = 1);
};

class Rect : public Point {
public:
	Rect();
	Rect(int x, int y, int width, int height);
	~Rect();

protected:
	int width;
	int height;

public:
	int Top() const;
	int Bottom() const;
	int Left() const;
	int Right() const;
	int Width() const;
	int Height() const;

	Point TopLeft() const;
	Point TopRight() const;
	Point BottomLeft() const;
	Point BottomRight() const;

	void ClipTo(const Rect& boundary);
	void ClipTo(const Rect& boundary, int offset);
	void ClipToTight(const Rect& boundary);
	void ClipToTight(const Rect& boundary, int offset);

	bool OutOfBound(const Rect& boundary);
	
	void DrawSelf(ConsoleGameEngine* engine) const;
	
	void SetPosition(int x, int y);
	void RandomizeX(const Rect& boundary);

	bool CollisionWith(const Rect& other) const;
};