#include "Visible.h"
#include "../Animation/Animation.h"
class Ball;

class Platform : public Visible
{
	std::unique_ptr<Animation> m_animator;
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
	void OnOutsideTheWidow()
	{
		m_x = initialPosition.first;
		m_y = initialPosition.second;
	}

public:
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getW() { return s_Width; }
	int getH() { return s_Height; }
	int getMiddle() { return m_x + s_Width / 2; }
	void getCoordinates(int& x, int& y, int& w, int& h) const;
	float getRelY();
	float getVelocity() { return m_animator->getVelocity(); }

	friend Arkanoid;

};