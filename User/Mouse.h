#pragma once
#include <map>
#include "../Framework.h"

using MouseState = std::map< FRMouseButton, bool>;// 1 when was pressed, but not released 

class Mouse
{
	static int x, y, xrelative, yrelative;
	static bool s_Enabled;	//uinused
	static MouseState s_MouseState;
	//static bool isButtonPressed(FRMouseButton button);

	friend class Arkanoid;
};