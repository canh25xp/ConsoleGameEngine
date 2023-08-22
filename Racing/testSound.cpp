#include "ConsoleGameEngine.h"

class Test : public ConsoleGameEngine {
public:
	Test() {
		m_sAppName = L"Matrix";
		EnableSound();
	}

private:
	int id;

protected:
	bool OnUserCreate() {
		id = LoadAudioSample(L"assets/vine_boom.wav");
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) {
		if (m_keys[VK_SPACE].bPressed)
			PlaySample(id);
		return true;
	}
};

int main() {
	Test game;
	game.ConstructConsole(100, 80, 8, 8);
	game.Start();
	return 0;
}
