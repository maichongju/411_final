#ifndef SRC_TRAFFIC_HPP_
#define SRC_TRAFFIC_HPP_

#include <cmath>

#include "../../Constant.hpp"
#include "TrafficLight.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
extern float GlobalTime, IdleTime;

class Traffic {
public:
	Traffic();
	void draw();
private:
	TrafficLight *t[4];
	float LightTime;
	void LightRule();
};


#endif /* SRC_TRAFFIC_HPP_ */
