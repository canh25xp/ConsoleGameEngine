#include "ConsoleGameEngine.h"

class Test : public ConsoleGameEngine {
public:
	Test();

protected:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

public:
	void ClearScreen();
	void UpdateScreen();
	void RainbowFill();
	void WaitKey(int vKey);
	void DrawGrid();

private:
	Sprite *spr;
	int x;
	int y;
	float duration;

};

int main() {
	Test test;
	test.ConstructConsole(120, 160, 4, 4);
	test.Start();

	return 0;
}

Test::Test(){
	spr = nullptr;
}

bool Test::OnUserCreate(){
	x=10;
	y=10;
	duration = 0;
	spr = new Sprite(L"car1.spr");
	return true;
}

bool Test::OnUserUpdate(float fElapseTime){
	//duration += fElapseTime;
	//if(duration > 0.01){
	//	y++;
	//	duration = 0;
	//}
	ClearScreen();
	DrawPartialSprite(x, y, spr, 0, 0, 10, 10);
	//DrawSprite(x, y, spr);
	return true;
}

void Test::ClearScreen() {
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_BLANK, BG_BLACK);
}

void Test::UpdateScreen() {
	COORD bufferCoord;
	COORD bufferSize;
	bufferSize.X = (short) m_nScreenWidth;
	bufferSize.Y = (short) m_nScreenHeight;
	bufferCoord.X = 0;
	bufferCoord.Y = 0;
	WriteConsoleOutput(m_hConsole, m_bufScreen, bufferSize, bufferCoord, &m_rectWindow);
}

void Test::RainbowFill() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, (i + j) % 255);
		}
	}
}

void Test::WaitKey(int vKey) {
	while ((0x8000 & GetAsyncKeyState(vKey)) == 0);
}

void Test::DrawGrid() {
	for (int i = 0; i < ScreenWidth(); i++) {
		for (int j = 0; j < ScreenHeight(); j++) {
			Draw(i, j, PIXEL_BLANK, ((i + j) % 2) ? COLOUR::BG_BLACK : COLOUR::BG_WHITE);
		}
	}
}