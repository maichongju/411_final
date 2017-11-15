#include "House.hpp"


House::House() {
	myCube = new Cube();
	myPyramid = new Pyramid();
	myPyramid->scale_change(1);
	myPyramid->translate(-1, 1, -1);


}


void House::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	myCube->draw();
	myPyramid->draw();
	glPopMatrix();
}

