#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

class Car : public Rect {
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	int getWidth() const;
	int getHeight() const;
	void drawSelf(ConsoleGameEngine* engine) const;

private:
	Sprite* spr;
};