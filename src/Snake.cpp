#include "Snake.hpp"

/**
 * Constructor
 */
Snake::Snake() {
	snake = new LinkedList();
	this->setDafeult();
}

/**
 * Function will set the default value for snake
 * @param x
 * 			x value for setting the first value
 * @param y
 * 			y value for setting the first value
 */
void Snake::setDafeult() {
	int i;
	for (i = SNAKE_START_LENGTH - 1; i >= 0; i--) {
		this->snake->append(GAME_ZONE_WIDTH / 2 - GAME_BLOCK_SIZE * i,
		GAME_ZONE_HEIGHT / 2);
	}
}
/**
 * Reset snake to the first place
 */
void Snake::reset() {
	snake->~LinkedList();
	this->setDafeult();
}

/**
 * Function for drawing snake
 */
void Snake::draw() {
	int i;
	Node *current = this->snake->head;
	for (i = 0; i < this->snake->size; i++) {
		glRecti(current->x, current->y, current->x + GAME_BLOCK_SIZE,
				current->y + GAME_BLOCK_SIZE);
		current = current->next;
	}
}

/**
 * Function will determined if snake have contact will the block
 */
void Snake::increase() {

}

