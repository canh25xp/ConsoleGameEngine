#pragma once

#include "Enemy.h"



void Enemy::EnemyGeneretion(int index) {
    if (_enemyAlive[index] == 0) {
        srand((int)time(0));
        _enemyPosition[index][0] = 3 + rand() % (SCREEN_WIDTH - 10);
        _enemyPosition[index][1] = 0;
        _enemyAlive[index] = 1;
    }
}

void Enemy::EraseEnemy(Map* pmap, int index) { 
    if (_enemyAlive[index] == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                GoToXY(j + _enemyPosition[index][0], i + _enemyPosition[index][1]);
                cout << ' ';
                pmap->_map[i + _enemyPosition[index][1]][j + _enemyPosition[index][0]] = ' ';
            }
        }
    }
}

void Enemy::DisplayEnemy(Map* pmap, int index){
    if (_enemyAlive[index] == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                GoToXY(j + _enemyPosition[index][0], i + _enemyPosition[index][1]);
                cout << _enemy[i][j];
                pmap->_map[i + _enemyPosition[index][1]][j + _enemyPosition[index][0]] = _enemy[i][j];
            }
        }
    }
}


void Enemy::EnemyGoDown(Map* pmap, int index) {
    if (_enemyAlive[index] == 1) {
        EraseEnemy(pmap, index);
        _enemyPosition[index][1]++;
        DisplayEnemy(pmap, index);
        
    }
}



