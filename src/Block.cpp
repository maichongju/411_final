#include <stdlib.h>

#include "Block.hpp"
#include <stdio.h>

/**
 * Constructor for Block class, default color is white
 */
Block::Block() {
	generate();
	size = GAME_BLOCK_SIZE;
}


/**
 * this will random generate the block location, if the random position is
 * the same position as the current one, then it will keep generate a new one
 * until it generate a different one
 */
void Block::generate() {
	GLint tx = rand() % (GAME_ZONE_WIDTH);
	GLint ty = rand() % (GAME_ZONE_HEIGHT);
	while (tx == this->x && ty == this->y) {
		tx = rand() % (GAME_ZONE_WIDTH);
		ty = rand() % (GAME_ZONE_HEIGHT);
	}
	this->x = tx;
	this->y = ty;
}

/**
 * Set the color for the block
 * @param red (0-1) float
 * @param green (0-1) float
 * @param blue (0-1) float
 * @param alpha (0-1) float
 */
void Block::setColor(float red, float green, float blue, float alpha) {
	color.setColor(red, green, blue, alpha);
}

/**
 * Function will draw the block
 */
void Block::draw() {
	printf("%d,%d\n", x, y);
	glColor4f(color.red, color.green, color.blue, color.alpha);
	glRecti(x, y, x + size, y + size);
}
