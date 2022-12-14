#pragma once
#include "Visible.h"

class Life;
using LifesList = std::list<Life*>;

class Life : public Visible
{
	static int s_LifeCounter;
	static LifesList s_lifeList;
	static int s_Width, s_Height;
	static int s_Limit;

	Life(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);
	virtual ~Life()
	{
		//destroySprite(s_Sprite);
		//--LifeCounter;
	}
	//Sprite* getSprite() override {
	//	return s_Sprite;
	//}

	static std::size_t damageLife();

	static std::size_t addLife();
	static bool canBuy()
	{
		return (s_lifeList.size() < s_Limit);	
	}
	friend Arkanoid;
	//friend Resizer;
};