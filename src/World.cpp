#include "World.hpp"

World::World() {
	block = new Block();
	snake = new Snake();
}

World::~World() {
	delete block;
	delete snake;

}

void World::draw() {
	if (GameStatus == GAME_STATUS_RUNNING) {
		this->block->draw();
	}
}

void World::reset() {
	this->~World();
	block = new Block();
	snake = new Snake();
}
