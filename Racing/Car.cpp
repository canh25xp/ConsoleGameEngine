#include "Car.h"

Car::Car() {
	spr = nullptr;
	position = Point(0, 0);
}

Car::Car(std::wstring sFile) {
	LoadSprite(sFile);
}

Car::~Car() {
	delete spr;
}

void Car::LoadSprite(std::wstring sFile) {
	this->spr = new Sprite(sFile);
}

void Car::ClipTo(const Rect& boundary) {
	if (position.x < boundary.Left())
		position.x = boundary.Left();

	if (position.x > boundary.Right())
		position.x = boundary.Right() - 1;

	if (position.y < boundary.Top())
		position.y = boundary.Top();

	if (position.y > boundary.Bottom())
		position.y = boundary.Bottom() - 1;
}

void Car::ClipTo(const Rect& boundary, int offset) {
	if (position.x < boundary.Left()+offset)
		position.x = boundary.Left()+offset;

	if (position.x >= boundary.Right()-offset)
		position.x = boundary.Right()-offset;

	if (position.y < boundary.Top()-offset)
		position.y = boundary.Top()-offset;

	if (position.y >= boundary.Bottom()+offset)
		position.y = boundary.Bottom()+offset;
}

void Car::ClipToTight(const Rect& boundary) {
	if (position.x < boundary.Left())
		position.x = boundary.Left();

	if ((position.x + spr->nWidth) >= boundary.Right())
		position.x = boundary.Right() - spr->nWidth;

	if (position.y < boundary.Top())
		position.y = boundary.Top();

	if (position.y >= boundary.Bottom())
		position.y = boundary.Bottom();
}

void Car::ClipToTight(const Rect& boundary, int offset) {
}
