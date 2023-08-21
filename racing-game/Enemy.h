#pragma once

#include "Common.h"
#include "Map.h"
//#include "Car.h"




class Enemy {
public:
	//Enemy();
	
	void DisplayEnemy(Map* pmap, int index);
	void EnemyGoDown(Map* pmap, int index);

	void EnemyGeneretion(int index);
	void EraseEnemy(Map* pmap, int index);

	int _enemyAlive[3] = { 0, 0, 0 };
	int _enemyPosition[3][2] = { {0,0}, {0, 0}, {0, 0} }; // (x, y)
	char _enemy[4][4] = {	' ','*','*',' ',
							'*','*','*','*',
							' ','*','*',' ',
							'*','*','*','*' };
};