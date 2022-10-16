#include "Header.h"

const char* Header::s_SpritePath{};// { "data/Header_600x64.png", };
Sprite* Header::s_Sprite{};// = Visible::InitSprite(Header::s_Sprite, Header::s_SpritePath);

Header::Header(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : Visible(a_width, a_height, x, y, a_relativeX, a_relativeY)
{
	//loadTextures(this, s_SpritePath);
	//s_Visibles.push_back(this);
	//setSpriteSize(s_Sprite, m_Width, m_Height);
}