#include "Arkanoid.h"
#include "User/KeyBoard.h"
#include "User/Mouse.h"

int Arkanoid::s_points{};
bool Arkanoid::s_EndOfGame{};
unsigned long Arkanoid::timeInSecs{};

Arkanoid::Arkanoid(int width, int height, bool fullscreen) : 
	WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{ fullscreen }, m_spBackground{},
	m_spHeader{}, m_spLife{}, m_detector{std::make_unique<CollisionDetector>()},
	/*start{ true },*/ m_TypesOfSpriteBlocks{ new SpritesBlocks },
	m_deltaTime{}, suppressMsg{ false }, m_clock{ Clock::s_GetClock() }, Framework(){}

Arkanoid::~Arkanoid()
{
	//delete members
	delete m_Background;
	delete m_Header;
	delete m_Platform;
	delete m_Ball;
	for (const auto& life : Life::s_lifeList)
	{
		delete life;
	}
	
	///////////////////delete graphic

	destroySprite(m_spBackground);
	destroySprite(m_spHeader);
	destroySprite(m_spLife);
	destroySprite(m_spPlatform);
	destroySprite(m_spBall);
	for (auto& sprite : *m_TypesOfSpriteBlocks)
	{
		destroySprite(sprite.second);
	}
	////////////////////
	delete m_TypesOfSpriteBlocks;
	Clock::destroyClock();
}

void Arkanoid::PreInit(int& width, int& height, bool& fullscreen)
{
	if (!FULLSCREEN)				
	{
		width = WIDTH;
		height = HEIGHT;
	}

	fullscreen = FULLSCREEN;
}
bool Arkanoid::Init()
{
	std::cout << getTickCount() << std::endl;
	//Resizer::ResizerInit();
	getScreenSize(WIDTH, HEIGHT);
	//WIDTH = Resizer::getScreenWidth();
	//HEIGHT = Resizer::getScreenHeight();

	try
	{
		prepareEnv();
	}

	catch (const InitializationException& e)
	{
		std::cout << e.what << std::endl;
		return false;
	}
	
	std::cout << "Welcome in game: " << GetTitle() << " " << WIDTH << "x" << HEIGHT << "	After " <<getTickCount()<< " miliseconds everything is ready. Enjoy ;)" << std::endl;
	return true;

}

void Arkanoid::prepareEnv()
{
	std::cout << getTickCount() << std::endl;
	m_Background = new BackGround(1, 1, 0.f, 0.f); //(WIDTH, HEIGHT, 0, 0, 0, 0);
	m_Header = new Header(1, 800 / 64, 0.f, 0.f);//(WIDTH, 64, 0, 0, 0, 0);
	//std::cout << getTickCount() << std::endl;
	/////  lifes
	Life::s_LifeCounter = 1;
	giveLifes();
	///// blocks
	//std::cout << getTickCount() << std::endl;
	Block::createBlocks(WIDTH, HEIGHT,getHeadersBottomLX(),getHeadersBottomLY());
	//std::cout << getTickCount() << std::endl;

	m_Platform = new Platform(600 / (1.5f * 600 / 6), 800 / 50, 0.4f, 0.9f);
	m_Ball = new Ball(600 / 40, 800 / 40, 0.45f, 0.85f, m_Platform);	//zawsze mozna cos dopisac w konstruktorze, zeby ustawil sie wzgl platformy
	m_Platform->setBall(m_Ball);

	InitSprites();
}

void Arkanoid::InitSprites()
{
	m_spBackground = InitSprite(m_spBackground, "data/background.png");
	setSpriteSize(m_spBackground, BackGround::s_Width, BackGround::s_Height);

	m_spHeader = InitSprite(m_spHeader, "data/Header_600x64.png");
	setSpriteSize(m_spHeader, Header::s_Width, Header::s_Height);

	m_spLife = InitSprite(m_spLife, "data/life.png");
	setSpriteSize(m_spLife, Life::s_Width, Life::s_Height);
	//if (!Life::s_lifeList.empty())
	//{
	//	setSpriteSize(m_spLife, Life::s_lifeList.front()->m_Width, Life::s_lifeList.front()->m_Height);
	//}

	(*m_TypesOfSpriteBlocks)['B'] = InitSprite(m_spLife, "data/B.png");
	(*m_TypesOfSpriteBlocks)['G'] = InitSprite(m_spLife, "data/G.png");
	(*m_TypesOfSpriteBlocks)['R'] = InitSprite(m_spLife, "data/R.png");
	(*m_TypesOfSpriteBlocks)['O'] = InitSprite(m_spLife, "data/O.png");
	(*m_TypesOfSpriteBlocks)['Y'] = InitSprite(m_spLife, "data/Y.png");
	(*m_TypesOfSpriteBlocks)['P'] = InitSprite(m_spLife, "data/P.png");
	(*m_TypesOfSpriteBlocks)['#'] = InitSprite(m_spLife, "data/#.png");

	if (!Block::s_BlocksList.empty())
	{
		for (auto& block : Block::s_BlocksList)
		{
			setSpriteSize((*m_TypesOfSpriteBlocks)[block->m_Color], Block::s_Width, Block::s_Height);
		
		}
		
	}

	m_spPlatform = InitSprite(m_spPlatform, "data/platform.png");
	setSpriteSize(m_spPlatform, Platform::s_Width, Platform::s_Height);

	m_spBall = InitSprite(m_spBall, "data/ball.png");
	setSpriteSize(m_spBall, Ball::s_Width, Ball::s_Height);
	
}

Sprite* Arkanoid::InitSprite(Sprite* a_sprite, const char* a_SpritePath)
{
	a_sprite = createSprite(a_SpritePath);

	if (!a_sprite)
	{
		std::cout << "Sth went wrong while creating the sprite with a  given path: " << a_SpritePath << std::endl;
		throw InitializationException();

	}
	return a_sprite;
}

void Arkanoid::giveLifes()
{
	for (int i = 0; i < Life::s_LifeCounter; i++)
	{
		auto life = new Life(600 / 60, 800 / 60, i * 65.f / 600, 4.f / 800);
		Life::s_lifeList.push_back(life);

	}
}

void Arkanoid::Close() {

	}

bool Arkanoid::Tick() {
	if (!Life::s_lifeList.empty())
	{
		m_clock->Update();
		m_deltaTime = m_clock->getDeltaTime();

		//player didn`t catch the ball
		if (!m_Ball->m_animator->isInsideTheWindow(m_Ball) && m_Ball->launched)
		{
			damageLife();

		}

		if (int points = m_detector->UpdateBlocks(m_Ball, m_clock); points)
		{
			m_comboHits++;
			if (m_comboHits > 3)
			{
				s_points += points * 3;
				std::cout << "Combo hit!  + 15: " << s_points << std::endl;
			}
			else
			{
				s_points += points;
			}
			std::cout << "Current score: " << s_points << std::endl;
		}

		if (m_detector->WasCollisionWIthPlatformDetected(m_Ball, m_Platform))
		{
			m_comboHits = 0;
		}

		drawVisibles();

		if (isEndOfGame(this))
		{
			if (!suppressMsg2)
			{
				if (win())
					std::cout << "Win!  :D\n";
				if (loss())
					std::cout << "Loss!  :(\n";
				std::cout << "Congratulations! Your score is: " << s_points << std::endl;
				std::cout << "Press Right Mouse button to restart" << std::endl;
				suppressMsg2 = !suppressMsg2;
			}
			restart();
		}

		//update positions
		manageKeyboard();
		m_Ball->m_animator->moveBall(m_Ball, m_deltaTime);


	}
	
	return false;
	//return true; //exits the aplication	
}

void Arkanoid::damageLife() {
	m_Ball->OnOutsideTheWidow();
	m_Platform->OnOutsideTheWidow();
	KeyBoard::s_Enabled = false;
	showCursor(true);
	Life::damageLife();
}

void Arkanoid::manageKeyboard()
{
	if (KeyBoard::s_Enabled)
	{
		if (KeyBoard::isKeyPressed(FRKey::RIGHT))
			m_Platform->m_animator->moveRight(m_Platform->m_x, m_Platform, m_deltaTime);

		if (KeyBoard::isKeyPressed(FRKey::LEFT))
			m_Platform->m_animator->moveLeft(m_Platform->m_x, m_Platform, m_deltaTime);
	}


}

void Arkanoid::onMouseMove(int x, int y, int xrelative, int yrelative) {
		Mouse::x = x;
		Mouse::y = y;
		Mouse::xrelative = xrelative;
		Mouse::yrelative = yrelative;

	//std::cout << "xrelative, yrelative:  " << xrelative << ' ' << yrelative << std::endl;
	//std::cout << "x, y:  " << x<< ' ' << y<< std::endl;
}				

void Arkanoid::onMouseButtonClick(FRMouseButton button, bool isReleased) {
	if (isReleased)
	{
		switch (button)
		{
		case FRMouseButton::LEFT:

			//wystrzel kulke jesli kulka jest poza ekranem i masz zycia		lub
			//zagraj jeszcze raz
			if (m_Ball->m_animator->isInsideTheWindow(m_Ball) && !m_Ball->launched)
			{
				if (!Life::s_lifeList.empty())
				{
					m_Ball->launch(Mouse::x, Mouse::y);
					KeyBoard::s_Enabled = true;
					showCursor(false);

					
				}
				else if (isEndOfGame(this))		//not launched, in window, lack of lifes
				{
					std::cout << "GAME OVER" << std::endl;
					showCursor(true);
					return;
				}
			}
			break;

		case FRMouseButton::RIGHT:
			
			//losuj umiejetnosc
			if ( Life::canBuy())
			{
				if (s_points >= 20)
				{
					size_t lifesNum{};
					std::cout << "Ability bought. Score -20 points";
					//draw  add life  or damage life
					auto surprise = Shop::buyAbility(s_points);
					switch (surprise)
					{
					case Shop::Ability::Positive:
						Life::addLife();
						std::cout << "Positive: Life added.\n";
						break;
					case Shop::Ability::Negative:
						lifesNum = Life::damageLife();
						if (!lifesNum)
							restart();
						std::cout << "Congratulations! Your score is: " << s_points << std::endl;
						std::cout << "Negative: Life taken.\n";
						break;

					default:
						break;
					}
				}
				else
				{
					std::cout << "Sorry, too few points to buy ability" << std::endl;

				}


			}
			//else 
			//{

			//}
			//restart
			if ( isEndOfGame(this))
			{
				restart();

			}
			break;
		default:
			break;
		}
	}

}
void Arkanoid::restart() {
	Life::s_LifeCounter = 1;
	giveLifes();
	Block::turnOnVisibility();
	m_detector->ResetDetector();
	m_comboHits = 0;
	m_Ball->launched = false;
	KeyBoard::s_Enabled = true;
	suppressMsg = false;
	auto ballPos = m_Ball->initialPosition;
	m_Ball->m_x = ballPos.first;
	m_Ball->m_y = ballPos.second;
	s_points = 0;
	suppressMsg2 = false;
	showCursor(true);
	m_clock->resetImmuneFlag();
}


void Arkanoid::onKeyPressed(FRKey k)
{
	KeyBoard::s_keyboardState[k] = true;

}

void Arkanoid::onKeyReleased(FRKey k) {
	KeyBoard::s_keyboardState[k] = false;
	}

const char* Arkanoid::GetTitle()
	{
		return "Arcanoid";
	}

void Arkanoid::drawVisibles()
{
	//for (const auto& element : Visible::s_Visibles)
	//{
	//	drawSprite(element->getSprite(), element->m_x, element->m_y);
	//}
	drawSprite(m_spBackground, m_Background->m_x, m_Background->m_y);
	drawSprite(m_spHeader, m_Header->m_x, m_Header->m_y);

	for (const auto& life : Life::s_lifeList)
	{
		drawSprite(m_spLife, life->m_x, life->m_y);
	}
	Block::drawBlocks(*m_TypesOfSpriteBlocks);
	
	drawSprite(m_spBall, m_Ball->m_x, m_Ball->m_y);
	drawSprite(m_spPlatform,m_Platform->m_x,m_Platform->m_y	);

}
