#include "Resizer.h"
#include "Visible/Visible.h"
#include "Framework.h"

int Resizer::m_SreenWidth{};
int Resizer::m_ScreenHeight{};

void Resizer::UpdateWidth(Visible* visible)
{
	double WidthRatio = visible->m_ScreenWidthratio;
	int newWidth = static_cast<double>(m_SreenWidth) * WidthRatio;
	visible->m_Width = newWidth;
}
void Resizer::UpdateHeight(Visible* visible)
{
	double HeigthRatio = visible->m_ScreenHeigthratio;
	int newHeight = static_cast<double>(m_ScreenHeight) * HeigthRatio;
	visible->m_Height = newHeight;
}

void Resizer::UpdateCoordinates(Visible* visible)
{
	visible->m_x *= (1. - visible->m_ScreenWidthratio);
	visible->m_y *= (1. - visible->m_ScreenHeigthratio);
}

void Resizer::ResizerInit()
{
	getScreenSize(m_SreenWidth, m_ScreenHeight);
}