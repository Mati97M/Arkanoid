#include "Ball.h"
#include "Platform.h"

int Ball::s_Width{};
int Ball::s_Height{};
std::pair<int, int> Ball::initialPosition{};

Ball::Ball(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY, Platform* a_platform) : Visible(a_relativeX, a_relativeY), m_platform{ a_platform }
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!Ball::s_Width)
	{
		Ball::s_Width = scrWidth / widthDivider;
	}

	if (!Ball::s_Height)
	{
		Ball::s_Height = scrHeight / heightDivider;
	}
	m_x = m_platform->getMiddle() - s_Height / 2;
	m_y = m_platform->getY() - s_Height - 3;
	initialPosition = std::make_pair( m_x, m_y );

	m_animator = std::make_unique<Animation>(0.7f);
}

void Ball::getCoordinates(int& x, int& y, int& w, int& h) const
{
	x = static_cast<int>(m_x);
	y = static_cast<int>(m_y);
	w = Ball::s_Width;
	h = Ball::s_Height;
};