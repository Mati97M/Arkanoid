#pragma once
#include "Framework.h"
#include "Visible.h"

class BackGround : public Visible
{
	BackGround(const char* a_SpritePath, int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : Visible(a_SpritePath, a_width, a_height, x, y, a_relativeX, a_relativeY)
	{
		Resizer::UpdateWidth(this);
		Resizer::UpdateHeight(this);
		Resizer::UpdateCoordinates(this);
		setSpriteSize(m_Sprite, m_Width, m_Height);	
		s_Visibles.push_back(this);
	}
	friend Arkanoid;
	friend Resizer;
};