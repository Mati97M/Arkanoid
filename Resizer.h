#pragma once

class Arkanoid;
class Visible;

class Resizer
{
	static int m_SreenWidth;
	static int m_ScreenHeight;

	static void ResizerInit();

public:

	static void UpdateWidth(Visible* visible);
	static void UpdateHeight(Visible* visible);
	static void UpdateCoordinates(Visible* visible);
	static int getScreenHeight()
	{
		return m_ScreenHeight;
	}
	static int getScreenWidth()
	{
		return m_SreenWidth;
	}

	friend class Arkanoid;
};