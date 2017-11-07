#include "Snake.hpp"

/**
 * Constructor
 */
Snake::Snake() {
	body = new LinkedList();
	this->setDafeult();
	Shape = GAME_SHAPE_SQUARE;
}

/**
 * Function will set the default value for body
 * @param x
 * 			x value for setting the first value
 * @param y
 * 			y value for setting the first value
 */
void Snake::setDafeult() {
	int i;
	for (i = SNAKE_START_LENGTH - 1; i >= 0; i--) {
		this->body->append(GAME_ZONE_WIDTH / 2 - GAME_BLOCK_SIZE * i,
		GAME_ZONE_HEIGHT / 2);
	}
}

/**
 * Set the color for snake
 * @param red
 * @param green
 * @param blue
 * @param alpha
 */
void Snake::setColor(float red, float green, float blue, float alpha) {
	this->color.setColor(red, green, blue, alpha);
}

/**
 * Reset body to the first place
 */
void Snake::reset() {
	body->~LinkedList();
	this->setDafeult();
}

/**
 * Function for drawing body
 */
void Snake::draw() {
	int i;
	Node *current = this->body->head;
	glColor4f(color.red, color.green, color.blue, color.alpha);
	for (i = 0; i < this->body->size; i++) {
		if (this->Shape == GAME_SHAPE_SQUARE) {
		glRecti(current->x, current->y, current->x + GAME_BLOCK_SIZE,
					current->y + GAME_BLOCK_SIZE);
		} else if (this->Shape == GAME_SHAPE_CIRCLE) {
			circleMidpoint(current->x + GAME_BLOCK_SIZE / 2,
					current->y + GAME_BLOCK_SIZE / 2, current->x, current->y);
		}
		current = current->next;
	}
}

/**
 * Function will return if the current point is in the body
 * @param x
 * 			x value for the point
 * @param y
 * 			y value for the point
 * @return
 * 			true if in the body, otherwise false
 */
bool Snake::init(int x, int y) {
	return this->body->init(x, y);
}


/**
 * Function will change snake direction
 * @param direction
 * 				direction need to change to
 */

void Snake::changeDirection(int direction) {
int x = this->getHead()->x;
int y = this->getHead()->y;
switch (direction) {
case GAME_KEY_UP: {
	this->body->append(x, y + GAME_BLOCK_SIZE);
	break;
}
case GAME_KEY_DOWN: {
	this->body->append(x, y - GAME_BLOCK_SIZE);
	break;
}
case GAME_KEY_LEFT: {
	this->body->append(x - GAME_BLOCK_SIZE, y);
	break;
}
case GAME_KEY_RIGHT: {
	this->body->append(x + GAME_BLOCK_SIZE, y);
	break;
}

}
}

/**
 * Function will pop the last section of the body
 */
void Snake::bodypop() {
	this->body->pop();
}

/**
 * Function will get the head of the snake
 * @return
 * 			the node of the head
 */
Node *Snake::getHead() {
return this->body->peek();
}

/**
 * Same as init, except not checking the head position
 * @param x
 * @param y
 * @return
 */
bool Snake::initE(int x, int y) {
	return this->body->initE(x, y);
}

void Snake::circleFilled(GLint x1, GLint y1, GLint x, GLint y) {
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(x1 + x, y1 + y);
	glVertex2i(x1 - x, y1 + y);
	glVertex2i(x1 + x, y1 - y);
	glVertex2i(x1 - x, y1 - y);
	glVertex2i(x1 + y, y1 + x);
	glVertex2i(x1 - y, y1 + x);
	glVertex2i(x1 + y, y1 - x);
	glVertex2i(x1 - y, y1 - x);
	glEnd();
}
void Snake::circleMidpoint(GLint x1, GLint y1, GLint x2, GLint y2) {
	glLineWidth(1.0);
	GLint r = sqrt(pow((x1 - x2), 2) + pow(y1 - y2, 2));
	GLint p = 1 - r;
	GLint x = 0, y = r;
	while (x < y) {
		x++;
		if (p < 0) {
			p += 2 * x + 1;
		} else {
			y--;
			p += 2 * (x - y) + 1;
		}
			circleFilled(x1, y1, x, y);

	}

}
