#pragma once
#include <map>
#include "Framework.h"

using KeyBoardState = std::map< FRKey, bool>;// 1 when was pressed, but not released 

class KeyBoard
{
	static bool s_Enabled;
	static KeyBoardState s_keyboardState;
	static bool isKeyPressed(FRKey key);
	static bool isAnyKeyPressed();
	friend class Arkanoid;
};

