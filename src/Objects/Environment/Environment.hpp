#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>

class Environment {
public:
	Environment();
	void draw();
	void reset();
private:
	void drawFloor();
};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
