#include <iostream>
#include <string>
using namespace std;

#include "ConsoleGameEngine.h"


class OneLoneCoder_Matrix : public ConsoleGameEngine {
public:
	OneLoneCoder_Matrix() {
		m_sAppName = L"Matrix";
		EnableSound();
	}

private:
	int id;

protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate() {
		id = LoadAudioSample(L"vine_boom.wav");
		return true;
	}

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime) {
		if (m_keys[VK_SPACE].bPressed)
			PlaySample(id);
		return true;
	}
};


int main() {
	OneLoneCoder_Matrix game;
	game.ConstructConsole(100, 80, 8, 8);
	game.Start();
	return 0;
}
