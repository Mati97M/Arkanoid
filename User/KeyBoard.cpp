#include "KeyBoard.h"

KeyBoardState KeyBoard::s_keyboardState{};

bool KeyBoard::isAnyKeyPressed()
{
	//int pressed{};
	for (const auto& key : s_keyboardState)
	{
		if (key.second == true)
			return true;
			//pressed++;
	}
	return false;
}