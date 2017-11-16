
#ifndef SRC_OBJECTS_CYLINDER_HPP_
#define SRC_OBJECTS_CYLINDER_HPP_
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
class Cylinder {
public:
	Cylinder();
	Cylinder(Point *position, Color *color);
	void draw();
private:
	Point *position;
};



#endif /* SRC_OBJECTS_CYLINDER_HPP_ */
