#include "Common.h"

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

Rect::Rect() {
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

Rect::Rect(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rect::~Rect() {
}

int Rect::Top() const {
	return this->y;
}

int Rect::Bottom() const {
	return (this->y+height);
}

int Rect::Left() const {
	return this->x;
}

int Rect::Right() const {
	return (this->x + width);
}


Point Rect::TopLeft() const{
	return Point(this->x, this->y);
}

Point Rect::TopRight() const{
	return Point(this->x + width, this->y);
}

Point Rect::BottomLeft() const {
	return Point(this->x, this->y+height);
}

Point Rect::BottomRight() const {
	return Point(this->x + width, this->y + height);
}
