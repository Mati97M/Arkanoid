#pragma once
#include "Visible.h"

class BackGround : public Visible
{
	static int s_Width, s_Height;

	BackGround(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);

	virtual ~BackGround()
	{
		/*destroySprite(s_Sprite);*/
		//delete s_Sprite;  bo wyjatek
	}

	//Sprite* getSprite() override{
	//	return s_Sprite;
	//}
	friend Arkanoid;
	//friend Resizer;
};