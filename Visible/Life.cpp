#include "Life.h"

LifesList Life::s_lifeList{};
int Life::s_LifeCounter{};

int Life::s_Width{};
int Life::s_Height{};

Life::Life(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY) : Visible(a_relativeX, a_relativeY)
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!Life::s_Width)
	{
		Life::s_Width = scrWidth / widthDivider;
	}

	if (!Life::s_Height)
	{
		Life::s_Height = scrHeight / heightDivider;
	}
	//loadTextures(this, s_SpritePath);
	//s_Visibles.push_back(this);
	//setSpriteSize(s_Sprite, m_Width, m_Height);
}

