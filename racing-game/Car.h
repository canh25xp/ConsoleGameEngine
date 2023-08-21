#pragma once
#include "Common.h"
#include "Map.h"

class Car {
public:
	Car();

	void MoveLeft(Map* pmap);
	void MoveRight(Map* pmap);
	void DisplayCar(Map* pmap);
	bool Collision(Map* pmap);

	int _carPosition = SCREEN_WIDTH / 2;
	char _car[4][4] = {	' ','�','�',' ',
						'�','�','�','�',
						' ','�','�',' ',
						'�','�','�','�' };
};

