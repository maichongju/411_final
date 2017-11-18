#include "Traffic.hpp"


Traffic::Traffic() {
	t[0] = new TrafficLight(new Point(-0.3, 0, -0.4), TRAFFICLIGHT_SOUTH);
	t[1] = new TrafficLight(new Point(0.3, 0, 0.4), TRAFFICLIGHT_NORTH);
	t[2] = new TrafficLight(new Point(0.3, 0, -0.1), TRAFFICLIGHT_WEST);
	t[3] = new TrafficLight(new Point(-0.3, 0, -0.1), TRAFFICLIGHT_EAST);
	LightTime = 0;

	c = new Car(new Point(0, 0, 0), CAR_EAST);
	c->Moving = true;

}

void Traffic::draw() {
	LightRule();

	int i;
	for (i = 0; i < 4; i++) {
		t[i]->draw();
	}


	c->draw();

}

void Traffic::LightRule() {
	LightTime += 1;
	if (LightTime < 2000) {
		t[0]->setLight(TRAFFIC_LIGHT_GREEN);
		t[1]->setLight(TRAFFIC_LIGHT_GREEN);
		t[2]->setLight(TRAFFIC_LIGHT_RED);
		t[3]->setLight(TRAFFIC_LIGHT_RED);

	} else if (LightTime < 2500) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[1]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[2]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[3]->setLight(TRAFFIC_LIGHT_YELLOW);
	} else if (LightTime < 4500) {
		t[0]->setLight(TRAFFIC_LIGHT_RED);
		t[1]->setLight(TRAFFIC_LIGHT_RED);
		t[2]->setLight(TRAFFIC_LIGHT_GREEN);
		t[3]->setLight(TRAFFIC_LIGHT_GREEN);
	}
	else if (LightTime < 5000) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[1]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[2]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[3]->setLight(TRAFFIC_LIGHT_YELLOW);
	}
	else {
		LightTime = 0;
	}

}
