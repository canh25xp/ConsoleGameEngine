#include "Common.h"

using namespace myGame;

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

Rectangle::Rectangle() {
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

Rectangle::Rectangle(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

}

Rectangle::~Rectangle() {
}

Point Rectangle::TopLeft() {
	return Point(this->x, this->y);
}

Point Rectangle::TopRight() {
	return Point(this->x + width, this->y);
}

Point Rectangle::BottomLeft() {
	return Point(this->x, this->y+height);
}

Point Rectangle::BottomRight() {
	return Point(this->x + width, this->y + height);
}
