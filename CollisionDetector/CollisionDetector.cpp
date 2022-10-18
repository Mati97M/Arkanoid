#include "CollisionDetector.h"
#include "../Visible/Visible.h"
#include "../Visible/Block/Block.h"
#include "../Visible/Ball.h"
#include "../Visible/Platform.h"
#include "../Visible/Block/Block.h"

bool CollisionDetector::WasCollisionWithBlockDetected(Ball* ball, Block* visible)
{	//wczesniej sprawdzamy, czy jest visible na true, tu juz dzialamy tylko na takich
	int b_x, b_y, b_w, b_h;
	int v_x, v_y, v_w, v_h;

	ball->getCoordinates(b_x, b_y, b_w, b_h);
	visible->getCoordinates(v_x, v_y, v_w, v_h);

	if (b_x >= v_x - b_w &&
		b_x <= v_x + v_w &&
		b_y >= v_y - b_h &&
		b_y <= v_y + v_h
		)
	{
		ball->dx = -(ball->dx);
		ball->dy = -(ball->dy);
		return true;
	}
	else
		return false;

}

int CollisionDetector::UpdateBlocks(Ball* ball)
{
	for (auto& block : Block::s_BlocksList)
	{
		if (block->m_visible)
		{
			if (WasCollisionWithBlockDetected(ball, block))
			{
				block->m_visible = false;
				m_destroyedBlocks++;
				return 5;
			}
		}
	}
	return 0;
}
bool CollisionDetector::allBlocksDestroyed()
{
	return m_destroyedBlocks == Block::getBlocksCount();
}


bool CollisionDetector::WasCollisionWIthPlatformDetected(Ball* ball, Platform* platform)
{
	int b_x, b_y, b_w, b_h;
	int p_x, p_y, p_w, p_h;

	ball->getCoordinates(b_x, b_y, b_w, b_h);
	platform->getCoordinates(p_x, p_y, p_w, p_h);

	if (		
		b_x > p_x - b_w / 2 && 
		b_x < p_x + p_w &&
		b_y + b_h > p_y)
	{
		if (ball->dy < 0)
		{
			ball->dy = -(ball->dy);

		}
		return true;
	}
	return false;
}

