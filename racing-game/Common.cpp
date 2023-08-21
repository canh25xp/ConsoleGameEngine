#include "Common.h"


void GoToXY(SHORT posX, SHORT posY) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    SetConsoleCursorPosition(hStdout, Position);
}