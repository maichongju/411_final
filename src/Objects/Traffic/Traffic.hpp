#ifndef SRC_TRAFFIC_HPP_
#define SRC_TRAFFIC_HPP_

#include <cmath>
#include <stdio.h>
#include <time.h>
#include <stdio.h>

#include "../../Constant.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include "TrafficLight.hpp"
#include "Car.hpp"
#include "CarQueue.hpp"
extern float GlobalTime, IdleTime;

static const int MAXCAR = 10;

class Traffic {
public:
	Traffic();
	void draw();
	void MenuAddCar(int Facing);
	void MenuDeleteCar(int Facing);
private:
	CarQueue *Ready[4];
	CarQueue *Running[4];
	TrafficLight *t[4];
	float LightTime;
	void LightRule();
	void CarRule();
	void CarListRule(int Side);
	void AddCar(int Side);
	void DeleteCar(int Side); // Option
	void RunningRule();
	void ReadyRule();
	void RunningRuleHelp(int Facing, Car *car);

};


#endif
