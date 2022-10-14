// Arkanoid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Framework.h"
#include <iostream>
#include <string>

/* Test Framework realization */
class Arkanoid : public Framework {
	
	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};

public:
	Arkanoid(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{fullscreen}, Framework()
	{

	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		if (!FULLSCREEN)				
		{
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
		drawTestBackground();
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
struct Dimensions
{
	int Width;
	int Height;
	bool fullscreen{ true };
};

Dimensions get_sizes(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	//////////////// wymiary okna poczatek
	Dimensions dimensions{ get_sizes(argc,argv) };
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


Dimensions get_sizes(int argc, char* argv[])
{
	std::string dimensions = argv[3];
	size_t separatorPos = dimensions.find_first_of('x');
	
	if (separatorPos == std::string::npos)
		return Dimensions{ 0,0,true };

	std::string sWidth{ dimensions.substr(0,separatorPos) };
	std::string sHeight{ dimensions.substr(separatorPos + 1) };
	int Width = std::stoi(sWidth);
	int Height = std::stoi(sHeight);
	return Dimensions{ Width, Height,false };
}