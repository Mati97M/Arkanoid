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
	static int s_Width, s_Height;
	char m_Color;
	bool m_visible;

	Block(int widthDivider, int heightDivider, float a_relativeX, float a_relativeY);
	static void createBlocks(const int& screenWidth, const int& screenHeight, int startX, int startY);
	static void drawBlocks( SpritesBlocks & blockSprites);
	static void turnOnVisibility();
public:
	virtual void getCoordinates(int& x, int& y, int& w, int& h) const;

	friend class Arkanoid;
	friend class CollisionDetector;

};