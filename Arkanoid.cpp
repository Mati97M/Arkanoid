#include "Arkanoid.h"

Arkanoid::Arkanoid(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{ fullscreen }, spBackground{}, spHeader{}, spLife{}, Framework(){}

Arkanoid::~Arkanoid()
{
	//delete members
	delete m_Background;
	delete m_Header;
	for (const auto& life : Life::s_lifeList)
	{
		delete life;
	}

	///////////////////delete graphic
	destroySprite(spBackground);
	destroySprite(spHeader);
	destroySprite(spLife);
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
	Resizer::ResizerInit();

	try
	{
		prepareEnv();
	}
		
	catch (const InitializationException& e)
	{
		std::cout << e.what << std::endl;
		return false;
	}
	return true;
}

void Arkanoid::Close() {

	}

bool Arkanoid::Tick() {

		drawTestBackground();
		drawVisibles();

		return false;
	}

void Arkanoid::onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

void Arkanoid::onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

void Arkanoid::onKeyPressed(FRKey k) {
	}

void Arkanoid::onKeyReleased(FRKey k) {
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
	drawSprite(spBackground, m_Background->m_x, m_Background->m_y);
	drawSprite(spHeader, m_Header->m_x, m_Header->m_y);

	for (const auto& life : Life::s_lifeList)
	{
		drawSprite(spLife, life->m_x, life->m_y);
	}
		
}

void Arkanoid::prepareEnv()
{
	m_Background = new BackGround(WIDTH, HEIGHT, 0, 0, 0, 0);
	m_Header = new Header(WIDTH, 64, 0, 0, 0, 0);

	Life::s_LifeCounter = 1;
	for (int i = 0; i < Life::s_LifeCounter; i++)
	{
		auto life = new Life(128, 116, 0, 0, 0, 0);
		Life::s_lifeList.push_back(life);

	}

	InitSprites();
}

void Arkanoid::InitSprites()
{
	spBackground = InitSprite(spBackground, "data/background.png");
	setSpriteSize(spBackground, m_Background->m_Width, m_Background->m_Height);

	spHeader = InitSprite(spHeader, "data/Header_600x64.png");
	setSpriteSize(spHeader, m_Header->m_Width, m_Header->m_Height);

	spLife = InitSprite(spLife, "data/life.png");
	if (!Life::s_lifeList.empty())
	{
		setSpriteSize(spLife, Life::s_lifeList.front()->m_Width, Life::s_lifeList.front()->m_Height);
	}

}

Sprite* Arkanoid::InitSprite(Sprite* a_sprite, const char* a_SpritePath)	//////////////////!!!!!!!!!!!!!!!!  trzeba cos innego wymyslic!!!!!!!!!!!!!!!
{
	//if (!a_sprite)
	//{
	a_sprite = createSprite(a_SpritePath);
	//}

	if (!a_sprite)
	{
		std::cout << "Sth went wrong while creating the sprite with a  given path: " << a_SpritePath << std::endl;
		throw InitializationException();

	}
	return a_sprite;
}




