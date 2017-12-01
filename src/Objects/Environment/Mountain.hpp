#ifndef SRC_OBJECTS_ENVIRONMENT_MOUNTAIN_HPP_
#define SRC_OBJECTS_ENVIRONMENT_MOUNTAIN_HPP_

#include "../Basic/Pyramid.hpp"
#include "../Basic/Point.hpp"
#include "../../Constant.hpp"

class Mountain{
public:
	Mountain();
	Mountain(float x,float y,float z);
private:
	//Point *position;
	Pyramid *p;
	int TextureID;

};


#endif
