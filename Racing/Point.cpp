#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::MoveUp(int distance) {
	this->y -= distance;
}

void Point::MoveDown(int distance) {
	this->y += distance;
}

void Point::MoveRight(int distance) {
	this->x += distance;
}

void Point::MoveLeft(int distance) {
	this->x -= distance;
}

void Point::SetPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

void Point::RandomizeX(int min, int max) {
	this->x = min + rand() % (max - min);
}

void Point::RandomizeY(int min, int max) {
	this->y = min + rand() % (max - min);
}

int Point::GetX() const {
	return this->x;
}

int Point::GetY() const {
	return this->y;
}
