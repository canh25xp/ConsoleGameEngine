#include "Car.h"

Car::Car() {
	spr = nullptr;
	this->x = 0;
	this->y = 0;
	this->width = 10;
	this->height = 10;
}

Car::Car(std::wstring sFile) {
	this->spr = new Sprite(sFile);
	this->width = spr->nWidth;
	this->height = spr->nHeight;
}

Car::~Car() {
	delete spr;
}

int Car::getWidth() const {
	if(this->spr != nullptr)
		return this->spr->nWidth;
	return this->width;
}

int Car::getHeight() const {
	if(this->spr != nullptr)
		return this->spr->nHeight;
	return this->height;
}

void Car::drawSelf(ConsoleGameEngine* engine) const {
	if (this->spr != nullptr)
		engine->DrawSprite(this->x, this->y, this->spr);
	else
		engine->Fill(this->x, this->y, this->Right(), this->Bottom(), PIXEL_SOLID, FG_BLUE);
}