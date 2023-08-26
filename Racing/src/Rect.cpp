#include "Rect.h"

Rect::Rect() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
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
	return (this->y + this->height - 1);
}

int Rect::Left() const {
	return this->x;
}

int Rect::Right() const {
	return (this->x + this->width - 1);
}

int Rect::Width() const {
	return this->width;
}

int Rect::Height() const {
	return this->height;
}


Point Rect::TopLeft() const {
	return Point(this->x, this->y);
}

Point Rect::TopRight() const {
	return Point(this->x + this->width - 1, this->y);
}

Point Rect::BottomLeft() const {
	return Point(this->x, this->y + this->height - 1);
}

Point Rect::BottomRight() const {
	return Point(this->x + this->width - 1, this->y + this->height - 1);
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

	if (this->y < boundary.Top() + offset)
		this->y = boundary.Top() + offset;

	if (this->Bottom() > boundary.Bottom() - offset)
		this->y = (boundary.Bottom() - this->height + 1 - offset);
}

void Rect::DrawSelf(ConsoleGameEngine* engine, short c, short col) const {
	int x = this->x;
	int y = this->y;

	for (int d = 0; d < 4; d++) {
		while (x >= this->Left() && x <= this->Right() && y >= this->Top() && y <= this->Bottom()) {
			engine->Draw(x, y, c, col);
			x += dx[d];
			y += dy[d];
		}
		x -= dx[d];
		y -= dy[d];

		continue;
	}
}

bool Rect::CollisionWith(const Rect& other) const {
	if ((x + width - 1) <= other.x)
		return false;
	if (x >= (other.x + other.width - 1))
		return false;
	if (y >= (other.y + other.height))
		return false;
	if ((y + height) <= other.y)
		return false;

	return true;
}

bool Rect::OutOfBound(const Rect& boundary) {
	if (this->y > boundary.Bottom())
		return true;
	return false;
}