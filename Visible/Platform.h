#include "Visible.h"

class Platform : public Visible
{
	static int s_Width, s_Height;

	Platform(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);
	virtual ~Platform()
	{
		//destroySprite(s_Sprite);
	}
	//Sprite* getSprite() override {
	//	return s_Sprite;
	//}

	friend Arkanoid;
	//friend Resizer;
};