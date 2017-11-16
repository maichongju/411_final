#ifndef SRC_OBJECTS_SPHERE_HPP_
#define SRC_OBJECTS_SPHERE_HPP_
#include "Shape.hpp"
#include "Point.hpp"
#include "../../Color.hpp"
#include <math.h>
class Sphere: public Shape {
public:
	float radius;
	Sphere(Point *position, Color *color, float radius);
	void draw();
	void draw(Color *color, Point *p);
	void setColor(float r, float g, float b, float alpha);
private:
	Color *color;
};
#endif /* SRC_OBJECTS_SPHERE_HPP_ */
