#include "ConsoleGameEngine.h"
#include <string>
#include <vector>
#include <iostream>

const int LETTERS = 26;
const int NUMBERS = 10;
const int ALPHABET = LETTERS + NUMBERS;

const int FONT_HEIGHT = 13;
const int FONT_WIDTH = 10;

int TextToSprite(char c);

class Test : public ConsoleGameEngine {
public:
	Test();

public:
	std::vector<std::wstring> fontPath;

void DrawString(const char* str);


protected:
	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);

private:
	Sprite* textSpr[ALPHABET];
};

int main() {
	Test game;
	game.ConstructConsole(160, 160, 4, 4);

	game.fontPath.push_back(L"font/0.spr");
	game.fontPath.push_back(L"font/1.spr");
	game.fontPath.push_back(L"font/2.spr");
	game.fontPath.push_back(L"font/3.spr");
	game.fontPath.push_back(L"font/4.spr");
	game.fontPath.push_back(L"font/5.spr");
	game.fontPath.push_back(L"font/6.spr");
	game.fontPath.push_back(L"font/7.spr");
	game.fontPath.push_back(L"font/8.spr");
	game.fontPath.push_back(L"font/9.spr");

	game.fontPath.push_back(L"font/A.spr");
	game.fontPath.push_back(L"font/B.spr");
	game.fontPath.push_back(L"font/C.spr");
	game.fontPath.push_back(L"font/D.spr");
	game.fontPath.push_back(L"font/E.spr");
	game.fontPath.push_back(L"font/F.spr");
	game.fontPath.push_back(L"font/G.spr");
	game.fontPath.push_back(L"font/H.spr");
	game.fontPath.push_back(L"font/I.spr");
	game.fontPath.push_back(L"font/J.spr");
	game.fontPath.push_back(L"font/K.spr");
	game.fontPath.push_back(L"font/L.spr");
	game.fontPath.push_back(L"font/M.spr");
	game.fontPath.push_back(L"font/N.spr");
	game.fontPath.push_back(L"font/O.spr");
	game.fontPath.push_back(L"font/P.spr");
	game.fontPath.push_back(L"font/Q.spr");
	game.fontPath.push_back(L"font/R.spr");
	game.fontPath.push_back(L"font/S.spr");
	game.fontPath.push_back(L"font/T.spr");
	game.fontPath.push_back(L"font/U.spr");
	game.fontPath.push_back(L"font/V.spr");
	game.fontPath.push_back(L"font/W.spr");
	game.fontPath.push_back(L"font/X.spr");
	game.fontPath.push_back(L"font/Y.spr");
	game.fontPath.push_back(L"font/Z.spr");

	game.Start();

	return 0;
}


Test::Test() {
	m_sAppName = L"Test Text";
	for (int i = 0; i < ALPHABET; i++){
		textSpr[i] = nullptr;
	}
}

bool Test::OnUserCreate() {
	for (int i = 0; i < ALPHABET; i++){
		textSpr[i] = new Sprite(fontPath[i]);
	}
	return true;
}

bool Test::OnUserUpdate(float fElapsedTime) {
	//for (int i = 0; i < 10; i++){
	//	DrawSprite(12*i, 0, textSpr[i]);
	//}

	DrawString("HELLOWORLD");

	return true; 
}

int TextToSprite(char c){
	if(c >= 'A' && c <= 'Z')
		return ((int)c - 55);

	if(c >= '0' && c <= '9')
		return ((int)c - 48);
}

void Test::DrawString(const char* str){
	int j = 0, i= 0;
	int width = 13;
	int height = 13;
	for (int k = 0; str[k]!= '\0'; k++){
		if(str[i] == ' ')
			i += 13;
		if(i*13 > ScreenWidth()-13){
			j += 13;
			i = 0;
		}
		DrawSprite(13*i,j , textSpr[TextToSprite(str[k])]);
		i++;
	}
}