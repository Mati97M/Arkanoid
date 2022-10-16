#include "Visible.h"

VisiblesList Visible::s_Visibles{};


Visible::Visible(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : m_Width{ a_width }, m_Height{ a_height }, m_x{ x }, m_y{ y }, m_relativeX{ a_relativeX }, m_relativeY{ a_relativeY }
{
	m_ScreenHeigthratio = m_Height / static_cast<double>(Resizer::getScreenHeight());
	m_ScreenWidthratio = m_Width / static_cast<double>(Resizer::getScreenWidth());
	Resizer::UpdateWidth(this);
	Resizer::UpdateHeight(this);
	Resizer::UpdateCoordinates(this);
	
}