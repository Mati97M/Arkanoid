#include "Arkanoid.h"

Arkanoid::Arkanoid(int width, int height, bool fullscreen) : WIDTH{ width }, HEIGHT{ height }, FULLSCREEN{ fullscreen }, m_spBackground{}, m_spHeader{}, m_spLife{}, m_TypesOfSpriteBlocks{new SpritesBlocks }, Framework() {}

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

	destroySprite(m_spBackground);
	destroySprite(m_spHeader);
	destroySprite(m_spLife);
	for (auto& sprite : *m_TypesOfSpriteBlocks)
	{
		destroySprite(sprite.second);
	}
	////////////////////
	delete m_TypesOfSpriteBlocks;
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
	WIDTH = Resizer::getScreenWidth();
	HEIGHT = Resizer::getScreenHeight();

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

void Arkanoid::prepareEnv()
{
	m_Background = new BackGround(WIDTH, HEIGHT, 0, 0, 0, 0);
	m_Header = new Header(WIDTH, 64, 0, 0, 0, 0);

	/////  lifes
	Life::s_LifeCounter = 7;
	for (int i = 0; i < Life::s_LifeCounter; i++)
	{
		int x = 10 * i + 55 * i;
		auto life = new Life(55, 55, x, 5 , static_cast<double>(x)/ WIDTH, 5. / HEIGHT);
		Life::s_lifeList.push_back(life);

	}
	///// blocks
	Block::createBlocks(WIDTH, HEIGHT,getHeadersBottomLX(),getHeadersBottomLY());


	InitSprites();
}

void Arkanoid::InitSprites()
{
	m_spBackground = InitSprite(m_spBackground, "data/background.png");
	setSpriteSize(m_spBackground, m_Background->m_Width, m_Background->m_Height);

	m_spHeader = InitSprite(m_spHeader, "data/Header_600x64.png");
	setSpriteSize(m_spHeader, m_Header->m_Width, m_Header->m_Height);

	m_spLife = InitSprite(m_spLife, "data/life.png");
	if (!Life::s_lifeList.empty())
	{
		setSpriteSize(m_spLife, Life::s_lifeList.front()->m_Width, Life::s_lifeList.front()->m_Height);
	}

	(*m_TypesOfSpriteBlocks)['B'] = InitSprite(m_spLife, "data/B.png");
	(*m_TypesOfSpriteBlocks)['G'] = InitSprite(m_spLife, "data/G.png");
	(*m_TypesOfSpriteBlocks)['R'] = InitSprite(m_spLife, "data/R.png");
	(*m_TypesOfSpriteBlocks)['O'] = InitSprite(m_spLife, "data/O.png");
	(*m_TypesOfSpriteBlocks)['Y'] = InitSprite(m_spLife, "data/Y.png");
	(*m_TypesOfSpriteBlocks)['P'] = InitSprite(m_spLife, "data/P.png");

	if (!Block::s_BlocksList.empty())
	{
		for (auto& block : Block::s_BlocksList)
		{
			setSpriteSize((*m_TypesOfSpriteBlocks)[block->m_Color], block->m_Width, block->m_Height);
		
		}
		
	}
	
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


void Arkanoid::Close() {

	}

bool Arkanoid::Tick() {

		//drawTestBackground();
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
	drawSprite(m_spBackground, m_Background->m_x, m_Background->m_y);
	drawSprite(m_spHeader, m_Header->m_x, m_Header->m_y);

	for (const auto& life : Life::s_lifeList)
	{
		drawSprite(m_spLife, life->m_x, life->m_y);
	}
	Block::drawBlocks(*m_TypesOfSpriteBlocks);
}
