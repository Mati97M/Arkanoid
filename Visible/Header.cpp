#include "Header.h"

int Header::s_Width{};
int Header::s_Height{};

Header::Header(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY) : Visible(a_relativeX, a_relativeY)
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!Header::s_Width)
	{
		Header::s_Width = scrWidth / widthDivider;
	}

	if (!Header::s_Height)
	{
		Header::s_Height = scrHeight / heightDivider;
	}

	//loadTextures(this, s_SpritePath);
	//s_Visibles.push_back(this);
	//setSpriteSize(s_Sprite, m_Width, m_Height);
}

