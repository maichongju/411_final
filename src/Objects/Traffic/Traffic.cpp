#include "Traffic.hpp"

Traffic::Traffic() {
	t[0] = new TrafficLight(new Point(-0.3, 0, -0.4), TRAFFICLIGHT_SOUTH);
	t[1] = new TrafficLight(new Point(0.3, 0, 0.4), TRAFFICLIGHT_NORTH);
	t[2] = new TrafficLight(new Point(0.3, 0, -0.1), TRAFFICLIGHT_WEST);
	t[3] = new TrafficLight(new Point(-0.3, 0, 0.1), TRAFFICLIGHT_EAST);
	LightTime = 0;

	int i;
	for (i = 0; i < 4; i++) {

		Ready[i] = new CarQueue();
		Running[i] = new CarQueue();
	}

	AddCar(CAR_LIST_NORTH);
	AddCar(CAR_LIST_SOUTH);
	AddCar(CAR_LIST_EAST);
	AddCar(CAR_LIST_WEST);

}

/**
 * Function for Menu to add car to specific list
 * @param Facing
 * 				List need to be added See Constant.hpp	CAR_LIST
 */
void Traffic::MenuAddCar(int Facing) {
	AddCar(Facing);
}

/**
 * Function for menu to delete ready queue car
 * @param Facing
 * 				List need to be delete. See constant.hpp CAR_LIST
 */
void Traffic::MenuDeleteCar(int Facing) {
	DeleteCar(Facing);
}

/**
 * Function will delete and free the last Car object in the given list
 * If the given ready queue is empty, then it will not do anything
 * @param Facing
 * 				List need to be delete. See Constant.hpp CAR_LIST
 */
void Traffic::DeleteCar(int Facing) {
	Ready[Facing]->removeRear();
}
/**
 * Function will draw the car for the map
 */
void Traffic::draw() {
	LightRule();
	CarRule();

	//Draw Traffic Light
	int i;
	for (i = 0; i < 4; i++) {
		t[i]->draw();
	}

	// Will only draw the running car
	for (i = 0; i < 4; i++) {
		Car *temp = Running[i]->front;
		while (temp != 0) {
			temp->draw();
			temp = temp->next;
		}
	}

}

/**
 * Add car to the Given list number
 * @param Side
 * 				Number of list need to be added, See Constants.hpp CAT_LIST_
 */
void Traffic::AddCar(int Side) {
	int Facing;
	switch (Side) {
	case CAR_LIST_NORTH: {
		Facing = CAR_NORTH;
		break;
	}
	case CAR_LIST_SOUTH: {
		Facing = CAR_SOUTH;
		break;
	}
	case CAR_LIST_EAST: {
		Facing = CAR_EAST;
		break;
	}
	case CAR_LIST_WEST: {
		Facing = CAR_WEST;
	}
	}
	Car *car = new Car(Facing);
	srand(time(NULL) + Side * 100); // Make random actually random
	car->WaitTime = rand() % 500 + 100;
	Ready[Side]->push(car);

}

/**
 * Switch traffic light
 */
void Traffic::LightRule() {
	LightTime += 1;
	if (LightTime < 1000) {
		t[0]->setLight(TRAFFIC_LIGHT_GREEN);
		t[1]->setLight(TRAFFIC_LIGHT_GREEN);
		t[2]->setLight(TRAFFIC_LIGHT_RED);
		t[3]->setLight(TRAFFIC_LIGHT_RED);

	} else if (LightTime < 1250) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[1]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[2]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[3]->setLight(TRAFFIC_LIGHT_YELLOW);
	} else if (LightTime < 2250) {
		t[0]->setLight(TRAFFIC_LIGHT_RED);
		t[1]->setLight(TRAFFIC_LIGHT_RED);
		t[2]->setLight(TRAFFIC_LIGHT_GREEN);
		t[3]->setLight(TRAFFIC_LIGHT_GREEN);
	} else if (LightTime < 2500) {
		t[0]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[1]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[2]->setLight(TRAFFIC_LIGHT_YELLOW);
		t[3]->setLight(TRAFFIC_LIGHT_YELLOW);
	} else {
		LightTime = 0;
	}

}

/**
 * Function for setting rule for car
 */
void Traffic::CarRule() {
	ReadyRule();
	RunningRule();
}

/**
 * Car Rule for Ready Queue
 */
void Traffic::ReadyRule() {
	int i;
	for (i = 0; i < 4; i++) {
		if (!Ready[i]->isEmpty()) {
			Car *current = Ready[i]->front;
			if (current->WaitTime == 0) {
				Running[i]->push(Ready[i]->pop());
				if (!Ready[i]->isEmpty()) {
					srand(time(NULL) + i * 100); // Make random actually random
					Ready[i]->front->WaitTime = rand() % 400 + 100;
				}
			} else {
				Ready[i]->front->WaitTime -= 1;
			}
		}
	}
}

/**
 * Car rule for running car
 */
void Traffic::RunningRule() {
	int i;
	for (i = 0; i < 4; i++) {
		if (!Running[i]->isEmpty()) {
			Car * car = Running[i]->front;
			while (car != 0) {
				RunningRuleHelp(i, car);
				car = car->next;
			}
		}

	}
}


/**
 * Helper function for RunningRule
 * @param Facing
 * 				Side of the current car. See Constant.hpp CAR_LIST_
 * @param car
 * 				Given Car Object
 */
void Traffic::RunningRuleHelp(int Facing, Car *car) {
	bool pass, OutMap;
	float CarPosition, TFF, TFS;
	switch (Facing) {
	case CAR_LIST_NORTH: {
		CarPosition = car->getZ();
		TFF = 0.35;
		TFS = 0.3;
		OutMap = CarPosition + 0.3 < -MAP_SIZE_HEIGHT;
		pass = t[0]->pass;
		break;
	}
	case CAR_LIST_SOUTH: {
		CarPosition = car->getZ();
		TFF = -0.5;
		TFS = -0.55;
		OutMap = CarPosition - 0.3 > MAP_SIZE_HEIGHT;
		pass = t[0]->pass;
		break;
	}
	case CAR_LIST_EAST: {
		CarPosition = car->getX();
		TFF = -0.7;
		TFS = -0.75;
		OutMap = CarPosition + -0.3 > MAP_SIZE_WIDTH;
		pass = t[2]->pass;
		break;
	}
	case CAR_LIST_WEST: {
		CarPosition = car->getX();
		TFF = 0.75;
		TFS = 0.7;
		OutMap = CarPosition + 0.3 < - MAP_SIZE_WIDTH;
		pass = t[2]->pass;
		break;
	}
	}

	// Out of the map, back to ready queue
	if (OutMap) {
		car->reset();
		Ready[Facing]->push(Running[Facing]->pop());

	}
	// Traffic Light
	else if (CarPosition < TFF && CarPosition > TFS) {
		if (pass) {
			car->Moving = true;
		} else {
			car->Moving = false;
		}
	} else {

		if (car->prev == 0) {
			car->Moving = true;
		} else {
			Car *front = car->prev;
			float distance;
			if (Facing == CAR_LIST_NORTH || Facing == CAR_LIST_SOUTH) {
				distance = abs(front->getZ() - car->getZ());
			} else {
				distance = abs(front->getX() - car->getX());
			}
			if (distance < 0.5) {
				car->Moving = false;
			} else {
				car->Moving = true;
			}
		}
	}

}

