#include "Ball.h"
#include "Platform.h"

int Ball::s_Width{};
int Ball::s_Height{};
std::pair<int, int> Ball::initialPosition{};

Ball::Ball(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY, Platform* a_platform) : Visible(a_relativeX, a_relativeY), m_platform{ a_platform }, dx{},dy{}, launched{}
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

	//m_animator = std::make_unique<Animation>(40*s_Height);	//commented for test
	m_animator = std::make_unique<Animation>(2*s_Height);	//test
}

void Ball::launch(int mouse_x, int mouse_y)
{
	int W, H;
	getScreenSize(W, H);
	dx = static_cast<float>(m_x - mouse_x)/W;
	dy = static_cast<float>(m_y - mouse_y)/H;
	launched = true;
}

void Ball::OnOutsideTheWidow()
{
	m_x = initialPosition.first;
	m_y = initialPosition.second;

	launched = false;
}

void Ball::getCoordinates(int& x, int& y, int& w, int& h) const
{
	x = static_cast<int>(m_x);
	y = static_cast<int>(m_y);
	w = Ball::s_Width;
	h = Ball::s_Height;
};