#include "Background.h"

const char* BackGround::s_SpritePath{};//{ "data/background.png" };
Sprite* BackGround::s_Sprite{};// = Visible::InitSprite(BackGround::s_Sprite, BackGround::s_SpritePath);/////////////////////////// nie da rady!!!  jeszcze nei zainicjowany modul graficzny

BackGround::BackGround(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : Visible(a_width, a_height, x, y, a_relativeX, a_relativeY)
{
	/*loadTextures( this, s_SpritePath);*/
	//s_Visibles.push_back(this);
	/*setSpriteSize(s_Sprite, m_Width, m_Height);*/
}