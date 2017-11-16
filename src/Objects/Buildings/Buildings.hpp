#ifndef SRC_OBJECTS_BUILDINGS_BUILDINGS_HPP_
#define SRC_OBJECTS_BUILDINGS_BUILDINGS_HPP_

#include "Building.hpp"

extern float GlobalTime;

class Buildings {
public:
	Buildings();
	void draw();
private:
	Building *b;
};



#endif /* SRC_OBJECTS_BUILDINGS_BUILDINGS_HPP_ */
