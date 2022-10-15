// Arkanoid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Framework.h"
#include <iostream>
#include <string>
#include "Visible/Visible.h"
#include "Resizer.h"
#include "Visible/Header.h"
#include "Visible/Background.h"

class Arkanoid : public Framework {
	
	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};
	//Resizer* m_Resizer{};
	Visible* m_Background{};
	Visible* m_Header{};

public:
	Arkanoid(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{fullscreen}, Framework()
	{}
	virtual ~Arkanoid()
	{
		//delete m_Resizer;
		delete m_Background;
	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		if (!FULLSCREEN)				
		{
			width = WIDTH;
			height = HEIGHT;
		}

		fullscreen = FULLSCREEN;
	}

	virtual bool Init() {
		Resizer::ResizerInit();

		try
		{
			m_Background = new BackGround("data/background.png", 600, 800, 0, 0, 0, 0);	////////////////////////// ZRÓB resizeowanie!!!!!!!!!!!!!!!!
			//setSpriteSize(m_Background->m_Sprite, m_Background->m_Width, m_Background->m_Height);

			m_Header = new Header("data/Header_600x64.png", 600, 64, 0, 0, 0, 0);
		}
		
		catch (const InitializationException& e)
		{
			std::cout << e.what << std::endl;
			return false;
		}
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		//static bool set{false};
		//if (!set)
		//{
		//	int width, height;
		//	getScreenSize(width, height);
		//	setSpriteSize(m_Background->m_Sprite, width, height);
		//	set = !set;
		//}

		drawTestBackground();
		drawSprite(m_Background->m_Sprite, m_Background->m_x, m_Background->m_y);
		drawSprite(m_Header->m_Sprite, m_Header->m_x, m_Header->m_y);

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

	void drawVisibles()
	{
		for (const auto& element : Visible::s_Visibles)
		{
			drawSprite(element->m_Sprite, element->m_x, element->m_y);
		}
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