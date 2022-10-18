#pragma once
#include <memory>

class Visible;
class Ball;
class Platform;
class Block;

class CollisionDetector
{
private:
	bool WasCollisionWithBlockDetected(Ball* ball, Block* visible);
	int UpdateBlocks(Ball* ball);
	bool WasCollisionWIthPlatformDetected(Ball* ball, Platform* platform);

	friend class Arkanoid;

};