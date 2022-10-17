#pragma once
class Visible;
class Ball;

class Animation
{
	float speed{};
	static int scrWidth, scrHeight;
	void moveRight(float& x, Visible* visible, unsigned dt);
	void moveLeft(float& x, Visible* visible, unsigned dt);

	void moveBall(Ball* ball, unsigned dt);

	void moveUp(float& y, unsigned int dt, Visible* visible);
	void moveDown(float& x, unsigned int dt, Visible* visible);

public:
	Animation(float a_speed);
	bool isInsideTheWindow(const Visible* visible);
	float getVelocity() { return speed; }

	friend class Arkanoid;

};