#include "ConsoleGameEngine.h"

// Define our static variables
std::atomic<bool> ConsoleGameEngine::m_bAtomActive(false);
std::condition_variable ConsoleGameEngine::m_cvGameFinished;
std::mutex ConsoleGameEngine::m_muxGame;