
#ifndef SRC_OBJECTS_CYLINDER_HPP_
#define SRC_OBJECTS_CYLINDER_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>

extern GLUquadric* QOBJ;
class Cylinder {
public:
	Cylinder();
	Cylinder(float x, float y, float z);
	void draw();
	void translate(float x, float y, float z);

private:
	float x, y, z;
	//Cylinder *cylinder;


};



#endif
