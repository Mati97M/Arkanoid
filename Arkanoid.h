#pragma once
#include "Visible/Header.h"
#include "Visible/Background.h"
#include "Visible/Life.h"
class Arkanoid : public Framework {

	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};
	//Resizer* m_Resizer{};
	Visible* m_Background{};
	Visible* m_Header{};

	Sprite* spBackground{};
	Sprite* spHeader{};
	Sprite* spLife{};


public:
	Arkanoid(int width, int height, bool fullscreen);
	virtual ~Arkanoid();

	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();

	virtual void Close();

	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

	virtual const char* GetTitle() override;

	void drawVisibles();

	void prepareEnv();

	void InitSprites();

	Sprite* InitSprite(Sprite* a_sprite, const char* a_SpritePath);
};

