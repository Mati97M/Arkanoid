#include "Background.h"

int BackGround::s_Width{};
int BackGround::s_Height{};

BackGround::BackGround(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY) : Visible(a_relativeX, a_relativeY)
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!BackGround::s_Width)
	{
		BackGround::s_Width = scrWidth / widthDivider;
	}

	if (!BackGround::s_Height)
	{
		BackGround::s_Height = scrHeight / heightDivider;
	}

	/*loadTextures( this, s_SpritePath);*/
	//s_Visibles.push_back(this);
	/*setSpriteSize(s_Sprite, m_Width, m_Height);*/
}