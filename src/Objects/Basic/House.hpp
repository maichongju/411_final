#include "Shape.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp"
#include <GL/glut.h>

#ifndef SRC_HOUSE_HPP_
#define SRC_HOUSE_HPP_

class House: public Shape {
protected:
	Cube* myCube;
	Pyramid* myPyramid;
public:
	House();
	void draw();
};




#endif
