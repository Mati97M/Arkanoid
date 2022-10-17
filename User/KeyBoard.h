#pragma once
#include <map>
#include "Framework.h"

using KeyBoardState = std::map< FRKey, bool>;// 1 when was pressed, but not released 

class KeyBoard
{
	static KeyBoardState s_keyboardState;
	static bool isAnyKeyPressed();
	friend class Arkanoid;
};

