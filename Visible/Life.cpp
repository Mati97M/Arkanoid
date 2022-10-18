#include "Life.h"
#include "../Arkanoid.h"

LifesList Life::s_lifeList{};
int Life::s_LifeCounter{};

int Life::s_Width{};
int Life::s_Height{};
int Life::s_Limit{ 6 };

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

std::size_t Life::damageLife() {
	auto damagedLife = s_lifeList.back();
	if(!s_lifeList.empty())
		s_lifeList.pop_back();
	s_LifeCounter--;
	delete damagedLife;
	Arkanoid::isEndOfGame();

	return s_lifeList.size();
}

std::size_t Life::addLife() {
	s_lifeList.push_back(new Life(600 / 60, 800 / 60, s_lifeList.size() * 65.f / 600, 4.f / 800));
	s_LifeCounter++;
	return s_lifeList.size();
}

