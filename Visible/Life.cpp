#include "Life.h"

const char* Life::s_SpritePath{};// { "data/60-Breakout-Tiles.png.png" };
Sprite* Life::s_Sprite{};// = Visible::InitSprite(Life::s_Sprite, Life::s_SpritePath);

LifesList Life::s_lifeList{};
int Life::s_LifeCounter{};

Life:: Life(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : Visible(a_width, a_height, x, y, a_relativeX, a_relativeY)
{
	//loadTextures(this, s_SpritePath);
	//s_Visibles.push_back(this);
	//setSpriteSize(s_Sprite, m_Width, m_Height);
}