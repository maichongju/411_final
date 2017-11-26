#ifndef SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_
#define SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_

#include "../Basic/Sphere.hpp"
#include "../../Texture/RGBpixmap.h"
#include "../Basic/Point.hpp"
#include "../../Constant.hpp"

extern RGBpixmap texture[];

class Solar{
public:
	Solar();
	void draw();
private:
	Sphere *sun,*moon;

};



#endif /* SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_ */
