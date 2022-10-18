#include "Platform.h"

int Platform::s_Width{};
int Platform::s_Height{};
std::pair<int, int> Platform::initialPosition{};

Platform::Platform(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY): m_ball{}, Visible(a_relativeX, a_relativeY)
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!Platform::s_Width)
	{
		Platform::s_Width = scrWidth / widthDivider;
	}

	if (!Platform::s_Height)
	{
		Platform::s_Height = scrHeight / heightDivider;
	}

	initialPosition = std::make_pair(m_x, m_y);
	m_animator = std::make_unique<Animation>(1.5f);
}

void Platform::getCoordinates(int& x, int& y, int& w, int& h) const
{
	x = static_cast<int>(m_x);
	y = static_cast<int>(m_y);
	w = Platform::s_Width;
	h = Platform::s_Height;
};

float Platform::getRelY()
{
	return m_relativeY;
}