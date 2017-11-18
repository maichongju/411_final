#ifndef SRC_OBJECTS_ENVIRONMENT_GROUND_HPP_
#define SRC_OBJECTS_ENVIRONMENT_GROUND_HPP_

#include <GL/glut.h>
#include "../../Constant.hpp"
class Ground {
public:
	Ground();
	void draw();
private:
	void Floor();
	void Road();


};

#endif
