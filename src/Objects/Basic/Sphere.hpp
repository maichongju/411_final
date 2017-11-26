#ifndef SRC_OBJECTS_SPHERE_HPP_
#define SRC_OBJECTS_SPHERE_HPP_
#include "Shape.hpp"
#include "Point.hpp"
#include "../../Color.hpp"
#include <math.h>
class Sphere: public Shape {
public:
	float radius;
	int textureID;
	Sphere(Point *position, Color *color, float radius);
	Sphere(Point *position, int TextureID,float radius);
	void draw();
	void draw(Color *color, Point *p);
	void drawtexture();
	void setColor(float r, float g, float b, float alpha);

private:
	Color *color;
	GLUquadric *quad;
};
#endif /* SRC_OBJECTS_SPHERE_HPP_ */
