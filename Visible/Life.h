#pragma once
#include "Visible.h"

class Life;
using LifesList = std::list<Life*>;

class Life : public Visible
{
	static int s_LifeCounter;
	static LifesList s_lifeList;

	Life(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY);
	virtual ~Life()
	{
		//destroySprite(s_Sprite);
		//--LifeCounter;
	}
	//Sprite* getSprite() override {
	//	return s_Sprite;
	//}

	friend Arkanoid;
	friend Resizer;
	friend void loadTextures(Sprite* a_sprite, const char* a_SpritePath);
};