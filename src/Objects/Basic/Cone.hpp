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
	Cone(float x, float y, float z);
	void draw();
	void translate(float x, float y, float z);

private:
	//Point *position;
	float x, y, z;
};




#endif /* SRC_OBJECTS_CONE_HPP_ */
