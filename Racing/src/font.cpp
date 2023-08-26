#include "font.h"

Font::Font(std::wstring fontFolder){
	OpenFolder(fontFolder);
	LoadFont();
}

Font::~Font() {
}

int Font::GetSpriteIndex(char c){
	if(c >= 'A' && c <= 'Z')
		return ((int)c - 55);

	if(c >= '0' && c <= '9')
		return ((int)c - 48);
	
	return -1;
}

void Font::OpenFolder(std::wstring fontFolder){
	fontPath[0] = fontFolder + L"/0.spr";
	fontPath[1] = fontFolder + L"/1.spr";
	fontPath[2] = fontFolder + L"/2.spr";
	fontPath[3] = fontFolder + L"/3.spr";
	fontPath[4] = fontFolder + L"/4.spr";
	fontPath[5] = fontFolder + L"/5.spr";
	fontPath[6] = fontFolder + L"/6.spr";
	fontPath[7] = fontFolder + L"/7.spr";
	fontPath[8] = fontFolder + L"/8.spr";
	fontPath[9] = fontFolder + L"/9.spr";
	fontPath[10] = fontFolder + L"/A.spr";
	fontPath[11] = fontFolder + L"/B.spr";
	fontPath[12] = fontFolder + L"/C.spr";
	fontPath[13] = fontFolder + L"/D.spr";
	fontPath[14] = fontFolder + L"/E.spr";
	fontPath[15] = fontFolder + L"/F.spr";
	fontPath[16] = fontFolder + L"/G.spr";
	fontPath[17] = fontFolder + L"/H.spr";
	fontPath[18] = fontFolder + L"/I.spr";
	fontPath[19] = fontFolder + L"/J.spr";
	fontPath[20] = fontFolder + L"/K.spr";
	fontPath[21] = fontFolder + L"/L.spr";
	fontPath[22] = fontFolder + L"/M.spr";
	fontPath[23] = fontFolder + L"/N.spr";
	fontPath[24] = fontFolder + L"/O.spr";
	fontPath[25] = fontFolder + L"/P.spr";
	fontPath[26] = fontFolder + L"/Q.spr";
	fontPath[27] = fontFolder + L"/R.spr";
	fontPath[28] = fontFolder + L"/S.spr";
	fontPath[29] = fontFolder + L"/T.spr";
	fontPath[30] = fontFolder + L"/U.spr";
	fontPath[31] = fontFolder + L"/V.spr";
	fontPath[32] = fontFolder + L"/W.spr";
	fontPath[33] = fontFolder + L"/X.spr";
	fontPath[34] = fontFolder + L"/Y.spr";
	fontPath[35] = fontFolder + L"/Z.spr";
}

bool Font::LoadFont(){
	int w = 0, h = 0;
	for (int i = 0; i < ALPHABET; i++){
		if(!fontSpr[i].Load(fontPath[i]))
			return false;
		if (fontSpr[i].nHeight > h)
			h = fontSpr[i].nHeight;
		if (fontSpr[i].nWidth > w)
			w = fontSpr[i].nWidth;
	}

	this->width = w;
	this->height = h;

	return true;
}

void Font::DrawString(ConsoleGameEngine* engine, std::string str, int x, int y){
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			x += width + 1;
			continue;
		}

		engine->DrawSprite(x, y, &fontSpr[GetSpriteIndex(str[i])]);
		x += width + 1;
	}
	last.x = x;
	last.y = y;
}

void Font::DrawString(ConsoleGameEngine* engine, std::string str, Point position) {
	int x = position.x;
	int y = position.y;
	DrawString(engine, str, x, y);
}

void Font::Endl() {
	last.y -= height;
}

Point Font::GetLastPosition() const {
	return last;
}