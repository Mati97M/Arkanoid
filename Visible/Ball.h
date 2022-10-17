#pragma once
#include "Visible.h"
#include "../Animation/Animation.h"
#include <memory>

class Platform;

class Ball : public Visible
{
	float dx, dy;
	bool launched;
	std::unique_ptr<Animation> m_animator;
	static int s_Width, s_Height;
	Platform* m_platform;
	static std::pair<int, int> initialPosition;

	Ball(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY, Platform* a_platform);
	virtual ~Ball()
	{

	}
	void launch(int mouse_x, int mouse_y);

public:
	void getCoordinates(int& x, int& y, int& w, int& h) const;
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getW() { return s_Width; }
	int getH() { return s_Height; }

	friend Arkanoid;
	friend Animation;
};