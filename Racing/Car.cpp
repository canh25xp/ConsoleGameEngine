#include "Car.h"

using namespace myGame;

Car::Car() {
	spr = nullptr;
	position = Point(0, 0);
}

Car::~Car() {

}

void Car::LoadSprite(std::wstring sFile) {
	this->spr = new Sprite(sFile);
}
