#include "Traffic.hpp"

Traffic::Traffic() {
	t[0] = new TrafficLight(new Point(-0.3, 0, -0.4), TRAFFICLIGHT_SOUTH);
	t[1] = new TrafficLight(new Point(0.3, 0, 0.4), TRAFFICLIGHT_NORTH);
	t[2] = new TrafficLight(new Point(0.3, 0, -0.1), TRAFFICLIGHT_WEST);
	t[3] = new TrafficLight(new Point(-0.3, 0, 0.1), TRAFFICLIGHT_EAST);
	LightTime = 0;

	int i;
	for (i = 0; i < 4; i++) {
		CarNum[i] = 0;
		CarFirst[i] = 0;
	}

	AddCar(CAR_LIST_NORTH);
	AddCar(CAR_LIST_NORTH);
	Cars[CAR_LIST_NORTH][0]->WaitTime = 0;
	//Cars[CAR_LIST_NORTH][0]->WaitTime = 0;
//	AddCar(CAR_LIST_SOUTH);
//	AddCar(CAR_LIST_EAST);
//	AddCar(CAR_LIST_WEST);
//	Cars[CAR_LIST_NORTH][0]->Moving = true;
//	Cars[CAR_LIST_SOUTH][0]->Moving = true;
//	Cars[CAR_LIST_EAST][0]->Moving = true;
//	Cars[CAR_LIST_WEST][0]->Moving = true;
}

void Traffic::draw() {
	LightRule();
	CarRule();

	int i, j;
	for (i = 0; i < 4; i++) {
		t[i]->draw();
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < CarNum[i]; j++) {
			Cars[i][j]->draw();
		}
	}

}

void Traffic::AddCar(int Side) {
	int num = CarNum[Side];
	if (num < MAXCAR) {
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
		Cars[Side][num] = new Car(Facing);
		CarNum[Side]++;
	}
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
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < CarNum[i]; j++) {
			Car *car = Cars[i][j];
			switch (i) {
			case CAR_LIST_NORTH: {
				printf("%f\n", car->getZ());
				// Out Map, reset
				if (car->getZ() + 0.3 < -MAP_SIZE_HEIGHT) {
					car->reset();
				}
				// Traffic Light
				else if (car->getZ() < 0.35 && car->getZ() > 0.3) {
					if (t[0]->pass) {
						car->Moving = true;
					} else {
						car->Moving = false;
					}
				} else {
					int k = j;
					if (k == 0) { // First car in the list
						k = CarNum[i] - 1;
					}
					if (k != 0) {
						if (CarFirst[i] == j) {
							if (car->Moving == false) {
								if (car->WaitTime == 0) {
									car->Moving = true;

								} else {
									car->WaitTime -= 1;
								}
							} else if (car->getZ() < MAP_SIZE_HEIGHT - 0.6) {
								CarFirst[i]++;
								if (CarFirst[i] == CarNum[i]) {
									CarFirst[i] = 0;
								}
							}

						} else {
							float distance = abs(
									car->getZ() - Cars[i][k]->getZ());
							if (distance < 0.5) {
								car->Moving = false;
							} else {
								if (car->WaitTime == 0) {
									car->Moving = true;
								} else {
									car->WaitTime -= 1;
								}
							}
						}
					} else {
						if (car->WaitTime == 0) {
							car->Moving = true;
						} else {
							car->WaitTime -= 1;
						}
					}

//					if (k != 0) {
//						// First Car First Time
//						if (CarFirst[i]) {
//							if (car->Moving == false) {
//								if (car->WaitTime == 0) {
//									car->Moving = true;
//								} else {
//									car->WaitTime -= 1;
//								}
//							} else {
//								if (car->getZ() < MAP_SIZE_HEIGHT - 0.5) {
//									CarFirst[i] = false;
//								}
//							}
//						} else {
//							float distance = abs(
//									car->getZ() - Cars[i][k]->getZ());
//							if (distance < 0.5) {
//								car->Moving = false;
//							} else {
//								if (car->WaitTime == 0) {
//									car->Moving = true;
//								} else {
//									car->WaitTime -= 1;
//								}
//							}
//						}
//					} else {
//						if (car->WaitTime == 0) {
//							car->Moving = true;
//						} else {
//							car->WaitTime -= 1;
//						}
//					}
//
//				}}
				}
				break;
			}
			case CAR_LIST_SOUTH: {
				if (car->getZ() - 0.3 > MAP_SIZE_HEIGHT) {
					car->reset();
				}
				//Traffic Light
				else if (car->getZ() < -0.5 && car->getZ() > -0.55) {
					if (t[0]->pass) {
						car->Moving = true;
					} else {
						car->Moving = false;
					}
				}
				break;
			}
			case CAR_LIST_EAST: { // -->
				if (car->getX() + -0.3 > MAP_SIZE_WIDTH) {
					car->reset();
				}
				//Traffic Light
				else if (car->getX() < -0.7 && car->getX() > -0.75) {
					if (t[2]->pass) {
						car->Moving = true;
					} else {
						car->Moving = false;
					}
				}
				break;
			}
			case CAR_LIST_WEST: { // <--
				if (car->getX() + 0.3 < - MAP_SIZE_WIDTH) {
					car->reset();
				}
				//Traffic Light
				else if (car->getX() > 0.7 && car->getX() < 0.75) {
					if (t[2]->pass) {
						car->Moving = true;
					} else {
						car->Moving = false;
					}
				}
				break;
			}
			}
		}
	}
}

