#pragma once
#include "Visible/Header.h"
#include "Visible/Background.h"
#include "Visible/Life.h"
#include "Visible/Block/Block.h"
#include "Visible/Platform.h"
#include "Visible/Ball.h"
#include "CollisionDetector/CollisionDetector.h"
#include <memory>
#include "Clock/Clock.h"


class Shop
{
	enum class Ability
	{
		Positive,
		Negative
	};
public:
	Ability static buyAbility(int& points) {
		points -= 20;
		if (rand() % 2 == 0)
			return Ability::Negative;
		else
			return Ability::Positive;
	}
	friend class Arkanoid;
};


class Arkanoid : public Framework {

	int WIDTH{};
	int HEIGHT{};
	bool FULLSCREEN{};
	/*bool start{true};*/
	//Resizer* m_Resizer{};
	BackGround* m_Background{};
	Header* m_Header{};
	Platform* m_Platform{};
	Ball* m_Ball{};
	std::unique_ptr<CollisionDetector> m_detector{};
	Clock* m_clock;

	Sprite* m_spBackground{};
	Sprite* m_spHeader{};
	Sprite* m_spLife{};
	SpritesBlocks* m_TypesOfSpriteBlocks;
	Sprite* m_spPlatform{};
	Sprite* m_spBall{};

	bool suppressMsg{};
	bool suppressMsg2{};
	float m_deltaTime{};
	//restart
	static int s_points;
	int m_comboHits{};
	static bool s_EndOfGame;
	static unsigned long timeInSecs;

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

	void giveLifes();
	bool win() {
		return m_detector->allBlocksDestroyed() && m_detector->WasCollisionWIthPlatformDetected(m_Ball,m_Platform);
	}
	bool loss() {
		return 	Life::s_lifeList.empty() || !m_Ball->m_animator->isInsideTheWindow(m_Ball);
	}

public:
	bool static isEndOfGame(Arkanoid* arkanoid) {
		return arkanoid->win() || arkanoid->loss();
	}

	int getHeadersBottomLX() { return m_Header->m_x; }
	int getHeadersBottomLY() { return m_Header->m_y + m_Header->s_Height; }

private:

	void drawVisibles();
	void manageKeyboard();
	void damageLife();
	void restart();

	//void manageMouse();

	void prepareEnv();

	void InitSprites();

	Sprite* InitSprite(Sprite* a_sprite, const char* a_SpritePath);

	
};

