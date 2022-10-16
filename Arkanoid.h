#pragma once
#include "Visible/Header.h"
#include "Visible/Background.h"
#include "Visible/Life.h"
#include "Visible/Block/Block.h"

class Arkanoid : public Framework {

	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};
	//Resizer* m_Resizer{};
	BackGround* m_Background{};
	Header* m_Header{};

	Sprite* m_spBackground{};
	Sprite* m_spHeader{};
	Sprite* m_spLife{};
	SpritesBlocks* m_TypesOfSpriteBlocks{};

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

	int getHeadersBottomLX() { return m_Header->m_x; }
	int getHeadersBottomLY() { return m_Header->m_y + m_Header->s_Height; }

private:

	void drawVisibles();

	void prepareEnv();

	void InitSprites();

	Sprite* InitSprite(Sprite* a_sprite, const char* a_SpritePath);

	
};

