
#ifndef SRC_OBJECTS_CYLINDER_HPP_
#define SRC_OBJECTS_CYLINDER_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>

extern GLUquadric* QOBJ;
class Cylinder {
public:
	int textureID;
	Cylinder();
	Cylinder(float x, float y, float z);
	Cylinder(float x, float y, float z, int TextureID);
	void draw();
	void drawtexture();
	void translate(float x, float y, float z);
	void scale(float a, float b, float c);

private:
	float x, y, z, a, b, c;
	GLUquadricObj *obj;
	//Cylinder *cylinder;


};



#endif
