/**
 * Car Object
 */

#ifndef SRC_OBJECTS_TRAFFIC_CAR_HPP_
#define SRC_OBJECTS_TRAFFIC_CAR_HPP_

#include "../../Constant.hpp"
#include "../Basic/Cube.hpp"
#include "../Basic/Sphere.hpp"
#include "../../Color.hpp"
#include "../Basic/Point.hpp"
class Car {
// Car size 0.3, 0.15, 0.2
public:
	bool Moving;
	int Facing;
	Car(Point *position, int Facing);
	void draw();
	void reset();
	void setColor();
private:
	Sphere *Wheels[4];
	Cube *Body;
	Point *position;
	float Speed;
	void move();
	void stop();
	void setWheels();

};
#endif
