#pragma once
#include "Visible.h"

class Header : public Visible
{
	static int s_Width, s_Height;

	Header(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);
	virtual ~Header()
	{
		//destroySprite(s_Sprite);
	}
	//Sprite* getSprite() override {
	//	return s_Sprite;
	//}
public:
	static int getH() { return s_Height; }
	friend Arkanoid;
	//friend Resizer;
};