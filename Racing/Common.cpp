#include "Common.h"

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int m_x, int y) {
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
		this->x = boundary.Right() - offset;

	if (this->y < boundary.Top() + offset)
		this->y = boundary.Top() + offset;

	if (this->y > boundary.Bottom() - offset)
		this->y = boundary.Bottom() - offset;
}

void Rect::ClipToTight(const Rect& boundary) {
	if (this->x < boundary.Left())
		this->x = boundary.Left();

	if (this->Right() > boundary.Right())
		this->x = (boundary.Right() - this->width + 2);

	if (this->y < boundary.Top())
		this->y = boundary.Top();

	if (this->Bottom() > boundary.Bottom())
		this->y = (boundary.Bottom() - this->height + 2);
}

void Rect::ClipToTight(const Rect& boundary, int offset) {
	if (this->x < boundary.Left() + offset)
		this->x = boundary.Left() + offset;

	if (this->Right() > boundary.Right() - offset)
		this->x = (boundary.Right() - this->width + 2 - offset);

	if (this->y < boundary.Top()+ offset)
		this->y = boundary.Top()+ offset;

	if (this->Bottom() > boundary.Bottom() - offset)
		this->y = (boundary.Bottom() - this->height + 1 - offset);
}

void Rect::SetPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Rect::DrawSelf(ConsoleGameEngine* engine) const {
	int x = this->x;
	int y = this->y;

	for (int d = 0; d < 4; d++) {
		while (x >= this->Left() && x <= this->Right() && y >= this->Top() && y <= this->Bottom()) {
			engine->Draw(x, y, PIXEL_BLANK, BORDER);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}

void Rect::RandomizePositionX(const Rect& boundary){
	this->x = rand() % boundary.Width();
	ClipToTight(boundary, 1);
}
