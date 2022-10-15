#pragma once
#include "Framework.h"
#include "Visible.h"

class BackGround : public Visible
{
	BackGround(const char* a_SpritePath, int a_width, int a_height, int x, int y) : Visible(a_SpritePath, a_width, a_height, x, y)
	{
		Resizer::UpdateWidth(this);
		Resizer::UpdateHeight(this);
		setSpriteSize(m_Sprite, m_Width, m_Height);	
	}
	friend Arkanoid;
	friend Resizer;
};