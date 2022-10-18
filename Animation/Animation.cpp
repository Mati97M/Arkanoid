#include "Animation.h"
#include "../Framework.h"
#include "../Visible/Ball.h"
#include "../Visible/Platform.h"
#include "../Visible/Header.h"

int Animation::scrWidth{};
int Animation::scrHeight{};

Animation::Animation(float a_speed) : speed{ a_speed } {
	if (!scrWidth || !scrHeight)
		getScreenSize(scrWidth, scrHeight);
}

bool Animation::isInsideTheWindow(const Visible* visible)
{
	int x, y, w, h;
	visible->getCoordinates(x, y, w, h);
	if (
		(x + w > scrWidth) ||
		(x < 0) ||
		(y < 0) ||
		(y + h > scrHeight)
		)
		return false;
	else
		return true;
}

void Animation::moveRight(float& x, Visible* visible, float dt)
{
	x += speed * dt; 
	if (!isInsideTheWindow(visible))
	{
		x = scrWidth - visible->getW();
	}
}
void Animation::moveLeft(float& x, Visible* visible, float dt)
{
	x -= speed * dt;
	if (!isInsideTheWindow(visible))
	{
		x = 0;
	}
}

void Animation::moveBall(Ball* ball, float dt)
{
	if (ball->launched)
	{
		auto pixelsX = speed/ ball->dx * dt;
		ball->m_x -= pixelsX;
		auto pixelsY = speed/ ball->dy * dt;
		ball->m_y -= pixelsY;


		if (ball->m_x < 0)
		{
			ball->m_x = 0;
			ball->dx = -(ball->dx);
		}
		if (ball->m_x + ball->s_Width > scrWidth)
		{
			ball->m_x = scrWidth - ball->s_Width;
			ball->dx = -(ball->dx);
		}
		if (ball->m_y < Header::getH()) 
		{
			ball->m_y = Header::getH();
			ball->dy = -(ball->dy);
		}   		
		//if (ball->m_x < 0 || ball->m_x + ball->s_Width > scrWidth)  ball->dx = -(ball->dx);
		//if (ball->m_y < Header::getH())   ball->dy = -(ball->dy);		//|| ball->m_y  + ball->s_Height > scrHeight)

	}

}


void Animation::moveUp(float& y, unsigned int dt, Visible* visible)		////////////////  zmienic na ksztalt tamtych  KOLEJNOSC
{
	//if (isInsideTheWindow(visible))
	//{
	//	y += dt * speed;
	//}
	////else		//////////////////   zrobic osobno, zeby ruch w pionie byl tylko dla kulki
	////	y

}
void Animation::moveDown(float& x, unsigned int dt, Visible* visible)
{
	//x -= dt * speed;
}