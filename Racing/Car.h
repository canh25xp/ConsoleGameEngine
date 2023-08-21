#pragma once
#include "ConsoleGameEngine.h"
#include "Common.h"

enum Direction{
	Up, Right, Down, Left
};

class Car : public Rect {
public:
	Car();
	Car(std::wstring sFile);
	~Car();

public:
	int Width() const;
	int Height() const;
	float Speed() const;
	void DrawSelf(ConsoleGameEngine* engine) const;

	void SetSpeed(float speed);
	
private:
	Sprite* m_spr;
	float m_speed; // pixel per seconds
	Direction m_d;
};