#ifndef SRC_TRAFFIC_HPP_
#define SRC_TRAFFIC_HPP_

#include <cmath>
#include <stdio.h>

#include "../../Constant.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include "TrafficLight.hpp"
#include "Car.hpp"
extern float GlobalTime, IdleTime;

static const int MAXCAR = 10;

class Traffic {
public:
	Traffic();
	void draw();
private:

	TrafficLight *t[4];
	Car *Cars[4][MAXCAR];
	int CarNum[4], CarFirst[4];
	float LightTime;
	void LightRule();
	void CarRule();
	void CarListRule(int Side);
	void AddCar(int Side);
	void DeleteCar(int Side); // Option
	//Car *c;

};


#endif
