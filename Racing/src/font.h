#include "ConsoleGameEngine.h"
#include <string>
#include <vector>
#include <iostream>
#include "Point.h"

const int LETTERS = 26;
const int NUMBERS = 10;
const int ALPHABET = LETTERS + NUMBERS;

const int FONT_HEIGHT = 7;
const int FONT_WIDTH = 5;

class Font {
public:
	Font(std::wstring fontFolder);
	~Font();

	void DrawString(ConsoleGameEngine* engine, std::string str, int x, int y);
	void DrawString(ConsoleGameEngine* engine, std::string str, Point position);
	void Endl() ;
	Point GetLastPosition() const ;

	void OpenFolder(std::wstring fontFolder);
	bool LoadFont();

private:
	std::wstring fontPath[ALPHABET];
	Sprite fontSpr[ALPHABET];

private:
	int GetSpriteIndex(char c);
	Point last;
	Point start;
	int width;
	int height;
};