#include "Car.h"

int car[4][4] = {
	0,1,1,0,
	1,1,1,1,
	0,1,1,0,
	1,1,1,1
};

Point2D::Point2D(){
	x=10;
	y=10;
}

Point2D::Point2D(int _x, int _y){
	x = _x;
	y = _y;
}

Car::Car(){
	spr_car = nullptr;
	position = Point2D(0,0);
	width = 4;
	height = 4;
}

Car::~Car(){

}

void Car::DrawSelf(cge::ConsoleGameEngine* grf){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if(car[i][j])
				grf->Draw(position.x+j, position.y+i, ' ', cge::COLOUR::BG_MAGENTA);
			else
				grf->Draw(position.x+j, position.y+i, ' ', cge::COLOUR::BG_BLACK);
		}
	}
}

void Car::Up(){
	position.y += height;
}
void Car::Right(){
	position.x += width;
}
void Car::Down(){
	position.y += height;
}
void Car::Left(){
	position.x -= width;
}