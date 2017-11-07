#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <stdio.h>
#include "Constant.hpp"
#include "Block.hpp"
#include "Snake.hpp"

extern int GameStatus;
extern Block block;
extern double snakemove;
extern int GameLevel;
extern int KeyDirection;
extern int Score;

class World {
private:
	float movecount;
	Block *block;
	Snake *snake;
public:
	World();
	~World();
	void draw();
	void reset();
	void checkEnd();
};

#endif /* WORLD_HPP_ */
