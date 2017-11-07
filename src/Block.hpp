
#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <GL/glut.h>
#include <stdlib.h>

#include "Color.hpp"
#include "Constant.hpp"

class Block {
public:
	Color color;
	GLint x, y;
	int size;
	Block();
	void draw();
	void setColor(float red, float green, float blue, float alpha);
private:
	void generate();
};



#endif /* BLOCK_HPP_ */
