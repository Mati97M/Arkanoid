#pragma once
#include "../Framework.h"
#include<iostream>
#include <string>
#include <list>
#include "../Resizer.h"


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

protected:
	//virtual Sprite* getSprite() = 0;
	static VisiblesList s_Visibles;
	int m_Width, m_Height;
	int m_x, m_y;
	const double m_relativeX;
	const double m_relativeY;
	double m_ScreenWidthratio = 1.;
	double m_ScreenHeigthratio = 1.;

	Visible(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY);

	virtual ~Visible()
	{
		//s_Visibles.pop_back();
		//delete m_Sprite;	// wyjatek!!!!!!!!!
	}

	static Sprite* InitSprite(Sprite* a_sprite, const char* a_SpritePath);

	friend class Arkanoid;
	friend class Resizer;
};

