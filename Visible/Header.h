#pragma once
#include "Visible.h"

class Header : public Visible
{
	Header(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY);
	virtual ~Header()
	{
		//destroySprite(s_Sprite);
	}
	//Sprite* getSprite() override {
	//	return s_Sprite;
	//}

	friend Arkanoid;
	friend Resizer;
};