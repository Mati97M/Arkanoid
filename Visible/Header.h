#pragma once
#include "Framework.h"
#include "Visible.h"
#include "../Resizer.h"

class Header : public Visible
{
	Header(const char* a_SpritePath, int a_width, int a_height, int x, int y) : Visible(a_SpritePath, a_width, a_height, x, y)
	{
		m_ScreenHeigthratio = 64/800.;
		Resizer::UpdateWidth(this);
		Resizer::UpdateHeight(this);
		setSpriteSize(m_Sprite, m_Width, m_Height);
	}
	friend class Arkanoid;
	friend class Resizer;
};