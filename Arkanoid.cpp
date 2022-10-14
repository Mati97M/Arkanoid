// Arkanoid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Framework.h"
#include <iostream>
#include <string>


class Arkanoid;

class Resizer
{
	int m_SreenWidth;
	int m_ScreenHeight;

	Resizer()
	{
		getScreenSize(m_SreenWidth, m_ScreenHeight);
	}
	friend class Arkanoid;

public:
	void Resize(int & a_spriteWidth, int & a_spriteHeight)
	{
		double scale{};
	}
};

class Visible
{
	Sprite* m_Sprite;
	const char* m_SpritePath;
protected:
	int m_Width, m_Height;
	int m_x, m_y;

	Visible(const char* a_SpritePath, int a_width, int a_height, int x, int y): m_SpritePath{a_SpritePath}, m_Width{a_width}, m_Height{a_height}, m_x{x}, m_y{y}
	{
		m_Sprite = createSprite(m_SpritePath);
		if (!m_Sprite)
		{
			std::cout << "Sth went wrong while creating the sprite with a  given path: " << a_SpritePath << std::endl;
			return;
		}
		setSpriteSize(m_Sprite, m_Width, m_Height);
	}
	friend class Arkanoid;
};

class Arkanoid : public Framework {
	
	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};
	Resizer* m_Resizer{};
	Visible* m_Background{};

public:
	Arkanoid(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{fullscreen}, Framework()
	{
		m_Resizer = new Resizer();
		m_Background = new Visible("background.png", WIDTH, HEIGHT, 0, 0);

	}
	virtual ~Arkanoid()
	{
		delete m_Resizer;
		delete m_Background;
	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		if (!FULLSCREEN)				
		{
			fullscreen = false;
			width = WIDTH;
			height = HEIGHT;
		}
		else
			fullscreen = FULLSCREEN;
	}

	virtual bool Init() {

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		drawSprite(m_Background->m_Sprite, m_Background->m_x, m_Background->m_y);
		//drawTestBackground();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}
};
struct SreenDimensions
{
	int Width;
	int Height;
	bool fullscreen{ true };
};

SreenDimensions get_sizes(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	//////////////// wymiary okna poczatek
	SreenDimensions dimensions{ get_sizes(argc,argv) };
	//////////////////// wymiary okna koniec

	bool fullscreen{};
	auto f = new Arkanoid(dimensions.Width, dimensions.Height,dimensions.fullscreen);
	//f->PreInit(width, height, fullscreen);
	
	//f->Init();
	//getScreenSize(width,height);
	run(f);
	std::cout << (f->GetTitle()) << std::endl;
	delete f;
	//return run();
	return 0;
}


SreenDimensions get_sizes(int argc, char* argv[])
{
	std::string dimensions = argv[3];
	size_t separatorPos = dimensions.find_first_of('x');
	
	if (separatorPos == std::string::npos)
		return SreenDimensions{ 0,0,true };

	std::string sWidth{ dimensions.substr(0,separatorPos) };
	std::string sHeight{ dimensions.substr(separatorPos + 1) };
	int Width = std::stoi(sWidth);
	int Height = std::stoi(sHeight);
	return SreenDimensions{ Width, Height,false };
}