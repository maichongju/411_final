#ifndef SRC_OBJECTS_SPHERE_HPP_
#define SRC_OBJECTS_SPHERE_HPP_
#include "Point.hpp"
#include <math.h>
class Sphere {
public:
	Point position;
	float red, green, blue, alpha; // RGB for the Sphere
	float xrotate, yrotate, zrotate;
	float radius;
	bool soild;
	Sphere();
	Sphere(GLfloat x, GLfloat y, GLfloat z, float r, float g, float b, bool s);
	void draw();
	void translate(GLfloat x, GLfloat y, GLfloat z);
	void rotate_mc(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
	void rotate_wc(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
	void scale(float s);
	void setColor(float r, float g, float b, float alpha);
};
#endif /* SRC_OBJECTS_SPHERE_HPP_ */
