#pragma once
#include "ConsoleGameEngine.h"

const COLOUR BACK_GROUND = BG_BLACK;
const COLOUR BORDER		 = BG_DARK_RED;

//Right, Down, Left, Up
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

namespace myGame {
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

	class Rectangle : public Point {
	public:
		int width;
		int height;

	public:
		Rectangle();
		Rectangle(int x, int y, int width, int height);
		~Rectangle();

	public:
		Point TopLeft();
		Point TopRight();
		Point BottomLeft();
		Point BottomRight();

		void Clip();
	};
}