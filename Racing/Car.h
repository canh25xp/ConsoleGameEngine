#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

class Car {
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	void LoadSprite(std::wstring sFile = L"assets/car1.spr");
	void ClipTo(const Rect& boundary);
	void ClipTo(const Rect& boundary, int offset);
	void ClipToTight(const Rect& boundary);
	void ClipToTight(const Rect& boundary, int offset);


public:
	Point position;	//top_left of the car
	Sprite* spr;
};