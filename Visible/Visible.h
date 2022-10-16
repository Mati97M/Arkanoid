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
	//static int m_Width, m_Height;
	float m_x, m_y;
	const double m_relativeX;
	const double m_relativeY;
	//double m_ScreenWidthratio = 1.;
	//double m_ScreenHeigthratio = 1.;

	Visible(float a_relativeX, float a_relativeY);

	virtual ~Visible()
	{
		//s_Visibles.pop_back();
		//delete m_Sprite;	// wyjatek!!!!!!!!!
	}

	friend class Arkanoid;
	//friend class Resizer;
};

