#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

enum Direction{
	Up, Right, Down, Left
};

class Car : public Rect{
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	int Width() const;
	int Height() const;
	void DrawSelf(ConsoleGameEngine* engine) const;
	void LoadSprite(Sprite* spr);

private:
	Sprite* m_spr;
};