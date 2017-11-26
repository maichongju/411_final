#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>
#include "Ground.hpp"
#include "Solar.hpp"
#include "../Basic/Cylinder.hpp"
#include "../Basic/Cone.hpp"
class Environment {
public:
	Environment();
	void draw();
	void reset();
private:
	Ground *G;
	Cylinder *T;
	Cone *T2;
	Solar *solar;

};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
