#include "Common.h"

Point2D::Point2D() {
	x = 0;
	y = 0;
}

Point2D::Point2D(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point2D::MoveUp(int distance) {
	this->y -= distance;
}

void Point2D::MoveDown(int distance) {
	this->y += distance;
}

void Point2D::MoveRight(int distance) {
	this->x += distance;
}

void Point2D::MoveLeft(int distance) {
	this->x -= distance;
}