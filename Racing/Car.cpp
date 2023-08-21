#include "Car.h"

Car::Car() {
	this->m_spr = nullptr;
	this->x = 0;
	this->y = 0;
	this->width = 12;
	this->height = 16;
	this->m_speed = 0;
}

Car::Car(std::wstring sFile) {
	this->m_spr = new Sprite(sFile);
	this->x = 0;
	this->y = 0;
	this->width = m_spr->nWidth;
	this->height = m_spr->nHeight;
	this->m_speed = 0;
}

Car::~Car() {
	delete m_spr;
}

int Car::Width() const {
	if(this->m_spr != nullptr)
		return this->m_spr->nWidth;
	return this->width;
}

int Car::Height() const {
	if(this->m_spr != nullptr)
		return this->m_spr->nHeight;
	return this->height;
}

void Car::DrawSelf(ConsoleGameEngine* engine) const {
	if (this->m_spr != nullptr)
		engine->DrawSprite(this->x, this->y, this->m_spr);
	else
		engine->Fill(this->x, this->y, this->Right(), this->Bottom(), PIXEL_SOLID, FG_BLUE);
}

float Car::Speed() const{
	return this->m_speed;
}

void Car::SetSpeed(float speed){
	this->m_speed = speed;
}