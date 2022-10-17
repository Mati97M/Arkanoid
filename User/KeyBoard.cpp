#include "KeyBoard.h"

KeyBoardState KeyBoard::s_keyboardState{};
bool KeyBoard::s_Enabled{ false };

bool KeyBoard::isKeyPressed(FRKey key)
{
	return s_keyboardState[key];
}

bool KeyBoard::isAnyKeyPressed()
{
	////int pressed{};
	//for (const auto& key : s_keyboardState)
	//{
	//	if (key.second == true)
	//		return true;
	//		//pressed++;
	//}
	return false;
}