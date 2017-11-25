#ifndef SRC_OBJECTS_CONE_HPP_
#define SRC_OBJECTS_CONE_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>
extern GLUquadric* QOBJ;
class Cone: Shape {
public:
	Cone();
	void draw();
private:
	Point *position;
};




#endif /* SRC_OBJECTS_CONE_HPP_ */
