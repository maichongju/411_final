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
extern int GameType;

class World {
private:
	float movecount;

public:
	World();
	~World();
	void draw();
	void reset();
	void checkEnd();
	Block *block;
	Snake *snake;
};

#endif /* WORLD_HPP_ */
