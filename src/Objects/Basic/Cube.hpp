#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3]; // RGB color for each face

public:
	Cube();
	void draw();
	void changeFaceColor(int i, float r, float g, float b);
	void scale(float x, float y, float z);
private:
	void draw_face(int);
};

#endif
