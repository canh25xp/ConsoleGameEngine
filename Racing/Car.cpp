#include "Car.h"

Car::Car() {
	spr = nullptr;
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

int Car::getWidth() const {
	return this->spr->nWidth;
}

int Car::getHeight() const {
	return this->spr->nHeight;
}

void Car::drawSelf(ConsoleGameEngine* engine) const {
	engine->DrawSprite(this->x, this->y, this->spr);
}