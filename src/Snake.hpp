#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Constant.hpp"
#include "LinkedList.hpp"
#include "Block.hpp"
#include "Color.hpp"


class Snake {
private:
	Color color;
	LinkedList *body;
	void setDafeult();
public:
	Snake();
	void draw();
	void reset();
	Node *getHead();
	void changeDirection(int direction);
	void setColor(float red, float green, float blue, float alpha);
	bool init(int x, int y);
	bool initE(int x, int y);
	void bodypop();
};



#endif
