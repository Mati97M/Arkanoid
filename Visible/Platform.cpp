#include "Platform.h"

int Platform::s_Width{};
int Platform::s_Height{};

Platform::Platform(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY) : Visible(a_relativeX, a_relativeY)
{
	int scrWidth, scrHeight;
	getScreenSize(scrWidth, scrHeight);

	if (!Platform::s_Width)
	{
		Platform::s_Width = scrWidth / widthDivider;
	}

	if (!Platform::s_Height)
	{
		Platform::s_Height = scrHeight / heightDivider;
	}

}