
#ifndef SRC_OBJECTS_CYLINDER_HPP_
#define SRC_OBJECTS_CYLINDER_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>

extern GLUquadric* QOBJ;
class Cylinder: Shape {
public:
	Cylinder();
	Cylinder(Point *position, Color *color);
	void draw();
private:
	Point *position;
};



#endif
