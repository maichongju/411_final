
#ifndef SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_
#define SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_

#include "../Basic/Cube.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"

class Light {
public:
	Light(Point *position, Color *lightcolor);
	void draw(Point *position);
	void setOn(bool on);
private:
	bool On;
	Color *lightcolor;
	Point *position;
};

class TrafficLight {
public:
	TrafficLight(Point *position);
	void draw();
private:
	Point *position;
	void setColor();


};



#endif /* SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_ */
