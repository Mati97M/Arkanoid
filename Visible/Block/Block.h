#pragma once
#include "../Visible.h"
#include <list>
#include <map>

class Block;
using BlocksList = std::list<Block*>;
using SpritesBlocks = std::map<char,Sprite*>;

class Block : public Visible
{
	static BlocksList s_BlocksList;
	//static int m_Width;
	//static int m_Width;
	char m_Color;
	bool m_visible;

	Block(int a_width, int a_height, int x, int y, double a_relativeX, double a_relativeY) : m_Color{}, m_visible{true}, Visible(a_width, a_height, x, y, a_relativeX, a_relativeY) {}
	virtual ~Block() {}
	static void createBlocks(const int screenWidth, const int screenHeight, int startX, int startY);
	static void drawBlocks( SpritesBlocks & blockSprites);

	friend class Arkanoid;
	friend class Resizer;

};