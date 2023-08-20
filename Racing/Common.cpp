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
	width = 0;
	height = 0;
}

Rect::Rect(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rect::~Rect() {
	//wtf should go here
}

int Rect::Top() const {
	return this->y;
}

int Rect::Bottom() const {
	return (this->y + height - 1);
}

int Rect::Left() const {
	return this->x;
}

int Rect::Right() const {
	return (this->x + width - 1);
}

int Rect::Width() const {
	return this->width;
}

int Rect::Height() const {
	return this->height;
}


Point Rect::TopLeft() const{
	return Point(this->x, this->y);
}

Point Rect::TopRight() const{
	return Point(this->x + width - 1, this->y);
}

Point Rect::BottomLeft() const {
	return Point(this->x, this->y + height - 1);
}

Point Rect::BottomRight() const {
	return Point(this->x + width - 1, this->y + height - 1);
}

void Rect::ClipTo(const Rect& boundary) {
	if (this->x < boundary.Left())
		this->x = boundary.Left();

	if (this->x > boundary.Right())
		this->x = boundary.Right();

	if (this->y < boundary.Top())
		this->y = boundary.Top();

	if (this->y > boundary.Bottom())
		this->y = boundary.Bottom();
}

void Rect::ClipTo(const Rect& boundary, int offset) {
	if (this->x < boundary.Left() + offset)
		this->x = boundary.Left() + offset;

	if (this->x > boundary.Right() - offset)
		this->x = boundary.Right() - offset - 1;

	if (this->y < boundary.Top() + offset)
		this->y = boundary.Top() + offset;

	if (this->y > boundary.Bottom() - offset)
		this->y = boundary.Bottom() - offset - 1;
}

void Rect::ClipToTight(const Rect& boundary) {
	if (this->x < boundary.Left())
		this->x = boundary.Left();

	if (this->Right() > boundary.Right())
		this->x = boundary.Right() - width + 1;

	if (this->y < boundary.Top())
		this->y = boundary.Top();

	if (this->Bottom() > boundary.Bottom())
		this->y = boundary.Bottom()  - height;
}

void Rect::ClipToTight(const Rect& boundary, int offset) {
}
