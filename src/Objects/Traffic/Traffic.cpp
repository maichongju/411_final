#include "Traffic.hpp"


Traffic::Traffic() {
	t[0] = new TrafficLight(new Point(1, 0, 1), TRAFFICLIGHT_SOUTH);
	t[1] = new TrafficLight(new Point(1, 0, 1), TRAFFICLIGHT_NORTH);
	t[2] = new TrafficLight(new Point(1, 0, 1), TRAFFICLIGHT_WEST);
	t[3] = new TrafficLight(new Point(1, 0, 1), TRAFFICLIGHT_EAST);
	LightTime = 0;

}

void Traffic::draw() {
	LightRule();
	t[0]->draw();


}

void Traffic::LightRule() {
	LightTime += 1;
	if (LightTime < 2000) {
		t[0]->setLight(TRAFFIC_LIGHT_RED);
	} else if (LightTime < 3000) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
	} else if (LightTime < 8000) {
		t[0]->setLight(TRAFFIC_LIGHT_GREEN);
	}
	else if (LightTime < 9000) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
	}
	else {
		LightTime = 0;
	}

}
