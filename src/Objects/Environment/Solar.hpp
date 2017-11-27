#ifndef SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_
#define SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_

#define SUN_SIZE		0.35
#define SUN_DIS			7
#define MOON_SIZE		0.2
#define MOON_DIS		6


#include "../Basic/Sphere.hpp"
#include "../../Texture/RGBpixmap.h"
#include "../Basic/Point.hpp"
#include "../../Constant.hpp"

extern RGBpixmap texture[];

class Solar{
public:
	Solar();
	~Solar();
	void draw();
	void settime(int time);
private:
	Sphere *sun,*moon;

};



#endif /* SRC_OBJECTS_ENVIRONMENT_SOLAR_HPP_ */
