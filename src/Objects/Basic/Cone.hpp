#ifndef SRC_OBJECTS_CONE_HPP_
#define SRC_OBJECTS_CONE_HPP_
#include "Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include <stdio.h>
extern GLUquadric* QOBJ;
class Cone {
public:
	int textureID;
	Cone();
	Cone(float x, float y, float z);
	Cone(float x, float y, float z, int TextureID);
	void draw();
	void drawtexture();
	void translate(float x, float y, float z);
	void scale(float a, float b, float c);

private:
	//Point *position;
	float x, y, z;
	float a, b, c;
	GLUquadricObj *obj;
};




#endif /* SRC_OBJECTS_CONE_HPP_ */
