#include "World.hpp"

/**
 * Constructor
 */
World::World() {
	block = new Block();
	snake = new Snake();
	movecount = 0;
}

/**
 * Deleted constructor
 */
World::~World() {
	delete block;
	delete snake;

}

/**
 * Draw the world
 */
void World::draw() {
	if (GameStatus == GAME_STATUS_RUNNING) {

		if (movecount <= GameLevel * 10) {
			movecount += abs(snakemove);
		} else {
			movecount = 0;
			this->snake->changeDirection(KeyDirection);
			if (!this->snake->init(block->x, block->y)) {
				this->snake->bodypop();
			} else {
				Score += GAME_BLOCK_SCORE;
				if (Score > 99999) {
					Score = 99999;
				}
			}
		}

		checkEnd();
		if (GameStatus != GAME_STATUS_END) {
			while (this->snake->init(this->block->x, this->block->y)) {
				block->generate();
			}
			this->block->draw();
			this->snake->draw();
		}
	}
}

/**
 * Reset the world
 */
void World::reset() {
	this->~World();
	block = new Block();
	snake = new Snake();
	movecount = 0;
}

/**
 * Check if snake is dead
 */
void World::checkEnd() {
	int x = this->snake->getHead()->x;
	int y = this->snake->getHead()->y;
	if (GameType == GAME_TYPE_NORMAL) {
		if (x < 0 || x == GAME_ZONE_WIDTH || y < 0 || y == GAME_ZONE_HEIGHT) {
			GameStatus = GAME_STATUS_END;
		}
	}
	if (this->snake->initE(x, y)) {
		GameStatus = GAME_STATUS_END;
	}
}
