#pragma once
#include "ConsoleGameEngine.h"
#include "Rect.h"

class Car : public Rect {
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	void DrawSelf(ConsoleGameEngine* engine) const;

protected:
	Sprite* m_spr;
};