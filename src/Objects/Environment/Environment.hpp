#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>
#include "Ground.hpp"
#include "Solar.hpp"
#include "../Basic/Cylinder.hpp"
#include "../Basic/Cone.hpp"

#include "Tree.hpp"
#include "../../Constant.hpp"
class Environment {
public:
	Environment();
	void draw();
	void reset();
	void setsolar(int time);
private:
	Ground *G;
	Tree *T;
	Tree *T2;
	Tree *T3;

	Solar *solar;

};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
