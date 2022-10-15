#pragma once
#include "Framework.h"
#include "Visible/Visible.h"

class Arkanoid;
class Visible;

class Resizer
{
	static int m_SreenWidth;
	static int m_ScreenHeight;

	static void ResizerInit()
	{
		getScreenSize(m_SreenWidth, m_ScreenHeight);
	}


public:
	static void UpdateWidth(Visible* visible);
	static void UpdateHeight(Visible* visible);

	friend class Arkanoid;
};

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