#pragma once
#include "ConsoleGameEngine.h"
#include "Point.h"

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

	void DrawSelf(ConsoleGameEngine* engine, short c, short col) const;

	bool CollisionWith(const Rect& other) const;
};