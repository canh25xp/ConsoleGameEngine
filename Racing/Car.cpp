#include "Car.h"


int car[16][12] = {
	1,1,0,0,3,3,3,3,0,0,1,1,
	1,1,2,2,3,3,3,3,2,2,1,1,
	1,1,0,0,3,3,3,3,0,0,1,1,
	0,0,0,0,3,3,3,3,0,0,0,0,
	0,0,3,3,3,3,3,3,3,3,0,0,
	0,0,3,3,3,3,3,3,3,3,0,0,
	0,0,3,3,4,4,4,4,3,3,0,0,
	0,0,3,3,4,4,4,4,3,3,0,0,
	0,0,3,3,4,4,4,4,3,3,0,0,
	0,0,3,3,4,4,4,4,3,3,0,0,
	1,1,3,3,4,4,4,4,3,3,1,1,
	1,1,3,3,3,3,3,3,3,3,1,1,
	1,1,3,3,3,3,3,3,3,3,1,1,
	0,0,0,0,3,3,3,3,0,0,0,0,
	0,0,0,0,3,3,3,3,0,0,0,0,
	3,3,3,3,3,3,3,3,3,3,3,3
};



Car::Car() {
	spr = nullptr;
	position = Point2D(10, 10);
	width = 12;
	height = 16;
}

Car::~Car() {

}

void Car::DrawSelf(ConsoleGameEngine* grf) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			switch (car[i][j]) {
				case 0:
					break;
				case 1:
					grf->Draw(position.x + j, position.y + i, ' ', CAR_TIRE);
					break;
				case 2:
					grf->Draw(position.x + j, position.y + i, ' ', CAR_AXIAL);
					break;
				case 3:
					grf->Draw(position.x + j, position.y + i, ' ', CAR_MAIN);
					break;
				case 4:
					grf->Draw(position.x + j, position.y + i, ' ', CAR_WINDOW);
					break;
				default:
					break;
			}
		}
	}
}