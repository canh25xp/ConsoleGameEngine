#include "Car.h"

Car::Car() {
	this->pSprite = nullptr;
	this->x = 0;
	this->y = 0;
	this->width = 12;
	this->height = 16;
}

Car::Car(std::wstring sFile) {
	this->pSprite = new Sprite(sFile);
	this->x = 0;
	this->y = 0;
	this->width = pSprite->nWidth;
	this->height = pSprite->nHeight;
}

Car::~Car() {
	delete pSprite;
}

void Car::DrawSelf(ConsoleGameEngine* engine) const {
	if (this->pSprite != nullptr)
		engine->DrawSprite(this->x, this->y, this->pSprite);
	else
		engine->Fill(this->x, this->y, this->Right(), this->Bottom(), PIXEL_SOLID, FG_BLUE);
}