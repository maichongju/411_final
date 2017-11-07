#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "Constant.hpp"
#include "Block.hpp"
#include "Snake.hpp"

extern int GameStatus;
extern Block block;
class World {
private:
	Block *block;
	Snake *snake;
public:
	World();
	~World();
	void draw();
	void reset();
};



#endif /* WORLD_HPP_ */
