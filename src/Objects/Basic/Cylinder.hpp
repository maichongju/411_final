
#ifndef SRC_OBJECTS_CYLINDER_HPP_
#define SRC_OBJECTS_CYLINDER_HPP_
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>

extern GLUquadric* QOBJ;
class Cylinder {
public:
	Cylinder();
	Cylinder(Point *position, Color *color);
	void draw();
private:
	Point *position;
};



#endif
