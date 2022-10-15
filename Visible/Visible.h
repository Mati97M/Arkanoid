#pragma once
#include "../Framework.h"
#include<iostream>
#include <string>
#include <list>

class Arkanoid;
class Resizer;

struct InitializationException
{
	std::string what{ "Error occured while creating sprite" };
};

class Visible;
using VisiblesList = std::list<Visible*>;

class Visible
{
	const char* m_SpritePath;
protected:

	static VisiblesList s_Visibles;

	Sprite* m_Sprite;
	int m_Width, m_Height;
	int m_x, m_y;
	const double m_relativeX;
	const double m_relativeY;
	double m_ScreenWidthratio = 1.;
	double m_ScreenHeigthratio = 1.;
	//static int s_BackgroundWidth, s_BackgroundHeight;		raczej z tego nie korzystam

	Visible(const char* a_SpritePath, int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : m_SpritePath{ a_SpritePath }, m_Width{ a_width }, m_Height{ a_height }, m_x{ x }, m_y{ y }, m_relativeX{a_relativeX}, m_relativeY{a_relativeY}
	{

		m_Sprite = createSprite(m_SpritePath);
		if (!m_Sprite)
		{
			std::cout << "Sth went wrong while creating the sprite with a  given path: " << a_SpritePath << std::endl;
			throw InitializationException();

		}
	}

	virtual ~Visible()
	{
		//delete m_Sprite;	// wyjatek!!!!!!!!!
	}

	friend class Arkanoid;
	friend class Resizer;
};
VisiblesList Visible::s_Visibles{};
//int Visible::s_BackgroundWidth{};
//int Visible::s_BackgroundHeight{};