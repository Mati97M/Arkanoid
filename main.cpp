// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Framework.h"
#include <iostream>
#include <string>
#include "Arkanoid.h"

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
	auto f = new Arkanoid(dimensions.Width, dimensions.Height, dimensions.fullscreen);
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