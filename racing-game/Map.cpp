#pragma once

//#include <iostream>
#include "Map.h"


//void Map::VietNamText(){
//	SetConsoleOutputCP(65001);
//}
//
//void Map::SetColor(int backgound_color, int text_color) {
//    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//    int color_code = backgound_color * 16 + text_color;
//    SetConsoleTextAttribute(hStdout, color_code);
//}
//
//
//void Map::SetTitle() {
//    SetConsoleTitle(L"Racing Game 2D");
//}
//
//void Map::ShowCur(bool CursorVisibility){
//    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_CURSOR_INFO ConCurInf;
//    ConCurInf.dwSize = 1;
//    ConCurInf.bVisible = CursorVisibility;
//    SetConsoleCursorInfo(handle, &ConCurInf);
//}


Map::Map() {
    _map = new char* [SCREEN_HEIGHT];
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        _map[i] = new char[SCREEN_WIDTH];
    }
}

//Map::~Map() {
//    for (int i = 0; i < SCREEN_HEIGHT; i++) {
//        delete[] _map[i];
//    }
//    delete[] _map;
//}

void Map::DisplayMap() {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            if (x < 3 || x >= SCREEN_WIDTH - 3) {
                _map[y][x] = '$';
                GoToXY(x, y);
                cout << '$';
            }
        }
    }
}

void Map::Score(Enemy* enemy, int index) {
    if (enemy->_enemyAlive[index] == 1) {
        _score++;
    }
    
}

void Map::DisplayScore() {
    GoToXY(50, 15);
    cout << "Score: " << _score;
}