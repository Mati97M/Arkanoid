#include "Visible.h"

class Ball;

class Platform : public Visible
{
	static int s_Width, s_Height;
	Ball* m_ball;
	static std::pair<int, int> initialPosition;

	Platform(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);
	virtual ~Platform()
	{

	}
	void setBall(Ball* a_ball) {
		m_ball = a_ball ? a_ball : nullptr;
	}

public:
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getMiddle() { return m_x + s_Width / 2; }

	friend Arkanoid;

};