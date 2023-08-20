#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

class Car : public Rect {
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	void LoadSprite(std::wstring sFile = L"assets/car1.spr");
	int getWidth() const;
	int getHeight() const;
	void drawSelf(ConsoleGameEngine* engine) const;

private:
	Sprite* spr;
};