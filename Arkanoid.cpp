// Arkanoid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Framework.h"
#include <iostream>
#include <string>

/* Test Framework realization */
class MyFramework : public Framework {

	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};

public:
	MyFramework(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{fullscreen}, Framework()
	{

	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		//std::cout << argc << std::endl;
		//for (int i = 0; i < argc; i++)
		//{
		//	std::cout << i << "\t" << argv[i] << std::endl;
		//}
		//std::cout << std::endl;
		//std::string dimensions = argv[3];
		//size_t separatorPos = dimensions.find_first_of('x');
		//std::string sWidth{ dimensions.substr(0,separatorPos) };
		//std::string sHeight{ dimensions.substr(separatorPos + 1) };
		//int Width = std::stoi(sWidth);
		////int Height = std::stoi(sHeight);
		//if (!fullscreen)				/////////////////////  dlaczego nie lapie breakpoint?
		//{
			width = WIDTH;
			height = HEIGHT;
		//}

		fullscreen = false;
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



int main(int argc, char* argv[])
{
	//////////////// wymiary okna poczatek
	std::cout << argc << std::endl;
	for (int i = 0; i < argc; i++)
	{
		std::cout <<i<<"\t"<< argv[i] << std::endl;
	}
	std::cout << std::endl;
	std::string dimensions = argv[3];
	size_t separatorPos = dimensions.find_first_of('x');
	std::string sWidth{ dimensions.substr(0,separatorPos)};
	std::string sHeight{ dimensions.substr(separatorPos + 1) };
	int Width = std::stoi(sWidth);
	int Height = std::stoi(sHeight);


	//////////////////// wymiary okna koniec
	int width{ 320 };
	int height{ 600 };
	bool fullscreen{};
	auto f = new MyFramework(Width, Height,fullscreen);
	//f->PreInit(width, height, fullscreen);
	
	//f->Init();
	//getScreenSize(width,height);
	run(f);
	std::cout << (f->GetTitle()) << std::endl;
	delete f;
	//return run();
	return 0;
}