#include "Visible.h"

//VisiblesList Visible::s_Visibles{};
int Visible::s_Width{};
int Visible::s_Height{};

Visible::Visible(float a_relativeX, float a_relativeY) : m_relativeX{ a_relativeX }, m_relativeY{ a_relativeY }
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	m_x = m_relativeX * scrWidth;
	m_y = m_relativeY * scrHeight;
	//m_ScreenHeigthratio = m_Height / static_cast<double>(Resizer::getScreenHeight());
	//m_ScreenWidthratio = m_Width / static_cast<double>(Resizer::getScreenWidth());
	//Resizer::UpdateWidth(this);
	//Resizer::UpdateHeight(this);
	//Resizer::UpdateCoordinates(this);
	
}