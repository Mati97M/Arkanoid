#include "Block.h"


BlocksList Block::s_BlocksList{};
//int Block::m_Width{};		// lepiej byloby, gdyby szerokosc i wysokosc i te wspolczynniki zw nimi byly statyczne  - dotyczy to tez pozostalych klas
//int Block::m_Width{};

void Block::createBlocks(const int screenWidth, const int screenHeight, int startX, int startY)
{
	constexpr int rows{ 22 };
	constexpr int cols{ 6 };
	char blocks[][cols] =
	{
			{'B', 'G', 'R', 'O', 'O', 'Y'},
			{'Y', 'G', 'B', 'B', 'B', 'O'},
			{'O', 'R', 'Y', 'R', 'G', 'B'},
			{'Y', 'O', 'R', 'G', 'B', 'Y'},
			{'Y', 'G', 'B', 'B', 'B', 'O'},
			{'O', 'R', 'Y', 'R', 'G', 'B'},
			{'B', 'G', 'R', 'O', 'O', 'Y'},
			{'G', 'P', 'P', 'P', 'P', 'R'},
			{'B', 'G', 'Y', 'R', 'R', 'O'},
			{'Y', 'O', 'R', 'B', 'B', 'G'},
			{'Y', 'G', 'B', 'R', 'B', 'O'},
			{'P', 'G', 'O', 'B', 'Y', 'P'},
			{'X', 'P', 'R', 'Y', 'P', 'X'},
			{'X', 'X', 'P', 'P', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'},
			{'X', 'X', 'X', 'X', 'X', 'X'}
	};

	int width = screenWidth / cols;
	int height = (screenHeight - startY) / rows;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (char color = blocks[row][col]; color != 'X')
			{
				int x =  col * width;
				int y = startY + row * height;
				auto block = new Block(width, height, x, y, static_cast<double>(x) / screenWidth, static_cast<double>(y) / screenHeight);// static_cast<double>(x)/ screenWidth, static_cast<double>(y)/ screenHeight);
				block->m_Color = blocks[row][col];

				s_BlocksList.push_back(block);
			}

		}
	}
}

void Block::drawBlocks(SpritesBlocks& blockSprites)
{
	for (auto* block : s_BlocksList)
	{
		if (block->m_visible)
			drawSprite(blockSprites[block->m_Color], block->m_x, block->m_y);
		else
			continue;
		//setSpriteSize(blockSprites[block->m_Color], block->m_Width, block->m_Height);
	}
}


//void Block::setBlocksSpriteSize(SpritesBlocks& blockSprites)
//{
//	for (auto* block : s_BlocksList)
//	{
//		drawSprite(blockSprites[block->m_Color], block->m_x, block->m_y);
//		//setSpriteSize(blockSprites[block->m_Color], block->m_Width, block->m_Height);
//	}
//}