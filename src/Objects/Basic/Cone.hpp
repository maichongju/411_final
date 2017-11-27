#ifndef SRC_OBJECTS_CONE_HPP_
#define SRC_OBJECTS_CONE_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>
extern GLUquadric* QOBJ;
class Cone {
public:
	Cone();
	void draw(float x, float y, float z);
private:
	Point *position;
};




#endif /* SRC_OBJECTS_CONE_HPP_ */
