#pragma once
class Visible;
class Animation
{
	float speed{};
	static int scrWidth, scrHeight;
	void moveRight(float& x, unsigned int dt, Visible* visible);
	void moveLeft(float& x, unsigned int dt, Visible* visible);
	void moveUp(float& y, unsigned int dt, Visible* visible);
	void moveDown(float& x, unsigned int dt, Visible* visible);

public:
	Animation(float a_speed);
	bool isInsideTheWindow(const Visible* visible);
	float getVelocity() { return speed; }

	friend class Arkanoid;

};