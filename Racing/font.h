#include "ConsoleGameEngine.h"
#include <string>
#include <vector>
#include <iostream>

const int LETTERS = 26;
const int NUMBERS = 10;
const int ALPHABET = LETTERS + NUMBERS;

const int FONT_HEIGHT = 7;
const int FONT_WIDTH = 5;

class Font{
public:
	Font();
	Font(std::wstring fontFolder);
	~Font();

	void Print(ConsoleGameEngine* engine, const char* str, int x, int y);

	void GetFont(std::wstring fontFolder);
	bool LoadFont();

private:
	std::wstring fontPath[ALPHABET];
	Sprite fontSpr[ALPHABET];

private:
	int GetSpriteIndex(char c);

};