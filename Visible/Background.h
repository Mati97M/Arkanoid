#pragma once
#include "Visible.h"

class BackGround : public Visible
{
	static const char* s_SpritePath;
	static Sprite* s_Sprite;

	BackGround(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY);

	virtual ~BackGround()
	{
		/*destroySprite(s_Sprite);*/
		//delete s_Sprite;  bo wyjatek
	}

	//Sprite* getSprite() override{
	//	return s_Sprite;
	//}
	friend Arkanoid;
	friend Resizer;
	friend void loadTextures(Sprite* a_sprite, const char* a_SpritePath);
};