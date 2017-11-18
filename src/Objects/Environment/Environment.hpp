#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>
#include "Ground.hpp"

class Environment {
public:
	Environment();
	void draw();
	void reset();
private:
	Ground *G;
};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
