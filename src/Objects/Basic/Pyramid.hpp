#include <GL/glut.h>
#include "Shape.hpp"

#ifndef SRC_PYRAMID_HPP_
#define SRC_PYRAMID_HPP_

class Pyramid: public Shape {
protected:
	GLfloat vertex[5][3];
	GLint face[4][3];
public:
	Pyramid();
	void draw();
	void setface();
	void drawface(int);
};


#endif
