#include "Mouse.h"

MouseState Mouse::s_MouseState{};
bool Mouse::s_Enabled{ true };
int Mouse::x{};
int Mouse::y{};
int Mouse::xrelative{};
int Mouse::yrelative{};

//bool Mouse::isButtonPressed(FRMouseButton button)
//{
//	onMous
//	onMouseButtonClick(button,)
//	return s_MouseState[button];
//}