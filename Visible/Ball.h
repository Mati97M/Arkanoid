#pragma once
#include "Visible.h"

class Platform;

class Ball : public Visible
{
	static int s_Width, s_Height;
	Platform* m_platform;
	static std::pair<int, int> initialPosition;

	Ball(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY, Platform* a_platform);
	virtual ~Ball()
	{

	}


	friend Arkanoid;

};