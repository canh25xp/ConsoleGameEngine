

#include <iostream>
//#include <Windows.h>
//#include <chrono>
#include <ctime>
//#include "Common.h"
#include "Car.h"
//#include "Map.h"
//#include "Enemy.h"



using namespace std;




int main() {
	Map* pmap = new Map();
	pmap->DisplayMap();
    pmap->DisplayScore();

	Car* car = new Car;
	car->DisplayCar(pmap);

    Enemy* enemy = new Enemy();
    enemy->EnemyGeneretion(0);
    enemy->DisplayEnemy(pmap, 0);

    clock_t  startTime = clock();
    clock_t  currentTime;
    double duration;

	while (1) {
        // Mỗi 5 giây thì tăng tốc thêm 10 đơn vị vận tốc 
        currentTime = clock();
        duration = (currentTime - startTime) / CLOCKS_PER_SEC;
        if (duration >= 5 && duration < 6) {
            if (pmap->_speed > 10) {
                    pmap->_speed = pmap->_speed - 10;
                }
            startTime = currentTime;
            duration = 0;
        }

        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') {
                car->MoveLeft(pmap);
            }
            if (ch == 'd' || ch == 'D') {
                car->MoveRight(pmap);
            }
            if (ch == 'w' || ch == 'W') {
                if (pmap->_speed > 100) {
                    pmap->_speed = pmap->_speed - 100;
                }
            }
            if (ch == 's' || ch == 'S') {
                pmap->_speed = pmap->_speed + 100;
            }
            if (ch == 27) {
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (car->Collision(pmap) == 1) {
                cout << i << " va cham";
                return 0;
            }
        }
        
        if (enemy->_enemyPosition[2][1] == 10 && enemy->_enemyAlive[0] == 0) {
            enemy->EnemyGeneretion(0);
            enemy->DisplayEnemy(pmap, 0);
        }
        if (enemy->_enemyPosition[0][1] == 10 && enemy->_enemyAlive[1] == 0) {
            enemy->EnemyGeneretion(1);
            enemy->DisplayEnemy(pmap, 1);
        }
        if (enemy->_enemyPosition[1][1] == 10 && enemy->_enemyAlive[1] == 0) {
            enemy->EnemyGeneretion(2);
            enemy->DisplayEnemy(pmap, 2);
        }

        Sleep(pmap->_speed);
        
        for (int i = 0; i < 3; i++) {
            if (enemy->_enemyPosition[i][1] == SCREEN_HEIGHT - 4) {
                enemy->EraseEnemy(pmap, i);
                pmap->Score(enemy, i);
                pmap->DisplayScore();
                enemy->_enemyAlive[i] = 0;
            }
            enemy->EnemyGoDown(pmap, i);
        }

        for (int i = 0; i < 3; i++) {
            if (car->Collision(pmap) == 1) {
                cout << i << " va cham";
                return 0;
            }
        }
	}

	return 0;
}