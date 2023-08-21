#pragma once

//#include "Common.h"
#include "Enemy.h"
//#include "Car.h"

using namespace std;

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 26
//#define WIN_WIDTH 70 



class Map{
public:
	Map();

	//~Map();

	//void VietNamText(); // Hiện tiếng việt
	//void SetColor(int backgound_color, int text_color); // Chỉnh màu chữ + nền nơi có chữ (= highlight)  trên console
	//void SetTitle(); // Cài Title của console = "Racing Game 2D"
	//void ShowCur(bool CursorVisibility); // Ẩn hiện con trỏ trên console
	
	void DisplayMap(); 
	void Score(Enemy* enemy, int index);
	void DisplayScore();




	int _speed = 500;
	int _score = 0;
	char** _map;
};
