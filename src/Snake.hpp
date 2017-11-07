#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Constant.hpp"
#include "LinkedList.hpp"
#include "Block.hpp"
#include "Color.hpp"


class Snake {
private:
	Color color;
	LinkedList *snake;
	void setDafeult();
public:
	Snake();
	void draw();
	void reset();
	void increase();
	void setColor(float red, float green, float blue, float alpha);
};



#endif
