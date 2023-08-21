#pragma once

#include "Car.h"



Car::Car() {
    
}


void Car::DisplayCar(Map* pmap) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            GoToXY(j + _carPosition, i + SCREEN_HEIGHT - 4);
            cout << _car[i][j];
            pmap->_map[i + SCREEN_HEIGHT - 4][j + _carPosition] = _car[i][j];
        }
    }
}


void Car::MoveLeft(Map* pmap) {
    if (_carPosition > 7) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                GoToXY(j + _carPosition, i + SCREEN_HEIGHT - 4);
                pmap->_map[i + SCREEN_HEIGHT - 4][j + _carPosition] = ' ';
                cout << ' ';
            }
        }
        _carPosition = _carPosition - 4;
        DisplayCar(pmap);
    }
}

void Car::MoveRight(Map* pmap) {
    if (_carPosition < SCREEN_WIDTH - 10) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                GoToXY(j + _carPosition, i + SCREEN_HEIGHT - 4);
                pmap->_map[i + SCREEN_HEIGHT - 4][j + _carPosition] = ' ';
                cout << ' ';
            }
        }
        _carPosition = _carPosition + 4;
        DisplayCar(pmap);
    }
}

bool Car::Collision(Map* pmap) {
    /*
        if (enemy->_enemyAlive[index] == 1) {
            if (enemy[index]._enemyPosition[index][1] >= SCREEN_HEIGHT - 7) {
                if (enemy[index]._enemyPosition[index][0] + 3 >= _carPosition && enemy[index]._enemyPosition[index][0] - 3 <= _carPosition) {
                    return 1;
                }
            }
        }*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pmap->_map[SCREEN_HEIGHT - 4 + j][_carPosition + i] == '*') {
                return 1;
            }
        }
    }
    
    return 0;
}