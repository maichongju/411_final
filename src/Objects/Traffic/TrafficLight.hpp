
#ifndef SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_
#define SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_

#include "../../Constant.hpp"
#include "../Basic/Cube.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include "../Basic/Sphere.hpp"

extern float GalobalTime, IdleTime;

class Light {
public:
	Light(Point *position, Color *lightcolor);
	void draw(Point *position);
	void setOn(bool on);
	void rotate(float x, float y, float z, float angle);
	void translate(float x, float y, float z);
private:
	bool On;
	Sphere *s;
	Color *lightcolor, *offlightcolor;
	Point *position;
};

/**
 * TrafficLight Class, default all light off
 */
class TrafficLight {
public:
	int Facing;
	bool pass;
	TrafficLight(Point *position, int location);
	void setLight(int light);
	void draw();
private:
	int LightUp;
	Point *position;
	Light *LightFront[3]; // 0 red, 1 yellow, 2 green
	Light *LightRear[3];
	Cube *Body;
	void setBodyColor();
	void setLight();
	void updatePass();

};



#endif /* SRC_OBJECTS_TRAFFIC_TRAFFICLIGHT_HPP_ */
