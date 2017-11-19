#include "Car.hpp"

Car::Car(int Facing) {
	Moving = false;
	Speed = 0.005;
	this->Facing = Facing;
	next = 0;
	prev = 0;
	setNew();
}

/**
 * Delete everything
 */
Car::~Car() {
	delete Wheels[0];
	delete Wheels[1];
	delete Wheels[2];
	delete Wheels[3];
	delete position;

}

/**
 * Draw the car
 */
void Car::draw() {
	if (Moving) {
		move();
	}
	Body->draw();
	Wheels[0]->draw();
	Wheels[1]->draw();
	Wheels[2]->draw();
	Wheels[3]->draw();
}

/**
 * Get the next Car which is attach to this car
 * @return
 * 			next car object
 */
Car *Car::getNext() {
	return this->next;
}

/**
 * Moving Function
 */
void Car::move() {
	int i;
	switch (Facing) {
	case CAR_EAST: {
		Body->translate(Speed, 0, 0);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(Speed, 0, 0);
		}
		position->translate(Speed, 0, 0);
		break;
	}
	case CAR_WEST: {
		Body->translate(-Speed, 0, 0);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(-Speed, 0, 0);
		}
		position->translate(-Speed, 0, 0);
		break;
	}
	case CAR_NORTH: {
		Body->translate(0, 0, -Speed);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(0, 0, -Speed);
		}
		position->translate(0, 0, -Speed);
		break;
	}
	case CAR_SOUTH: {
		Body->translate(0, 0, Speed);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(0, 0, Speed);
		}
		position->translate(0, 0, Speed);
	}
	}

}

/**
 * Function will set all the wheels for car
 */
void Car::setWheels() {
	// Create Wheels
	Wheels[0] = new Sphere(new Point(0.05, 0.04, 0.2), new Color(0, 0, 0, 0),
			0.04);
	Wheels[1] = new Sphere(new Point(0.25, 0.04, 0.2), new Color(0, 0, 0, 0),
			0.04);
	Wheels[2] = new Sphere(new Point(0.05, 0.04, 0), new Color(0, 0, 0, 0),
			0.04);
	Wheels[3] = new Sphere(new Point(0.25, 0.04, 0), new Color(0, 0, 0, 0),
			0.04);

	int i;
	for (i = 0; i < 4; i++) {
		Wheels[i]->rotate(0, 1, 0, Facing);
		Wheels[i]->translate(position->x, position->y, position->z + 0.1);

	}
}

/**
 * Function will set everything for the car
 */
void Car::setNew() {
	Body = new Cube();
	Body->scale(0.3, 0.15, 0.2);
	Body->rotate(0, 1, 0, Facing);
	srand(time(NULL)); // Make random actually random
	this->WaitTime = rand() % 500;
	this->Moving = false;
	switch (Facing) {
	case CAR_NORTH: {
		this->position = new Point(0.3, 0, MAP_SIZE_HEIGHT);
		Body->translate(0.3, 0.02, MAP_SIZE_HEIGHT + 0.1);
		break;
	}
	case CAR_SOUTH: {
		this->position = new Point(-0.3, 0, -MAP_SIZE_HEIGHT);
		Body->translate(-0.3, 0.02, -MAP_SIZE_HEIGHT + 0.1);
		break;
	}
	case CAR_EAST: {
		this->position = new Point(-MAP_SIZE_WIDTH - 0.3, 0, 0);
		Body->translate(-MAP_SIZE_WIDTH - 0.3, 0.02, 0.1);
		break;
	}
	case CAR_WEST: {
		this->position = new Point(MAP_SIZE_WIDTH + 0.3, 0, -0.2);
		Body->translate(MAP_SIZE_WIDTH + 0.3, 0.02, -0.1);
		break;
	}
	}
	setWheels();
}

/**
 * Reset the Car
 */
void Car::reset() {
	this->~Car();
	setNew();
}
/**
 * Return the current X
 * @return
 * 			Current X
 */
float Car::getX() {
	return this->position->x;
}

/**
 * Return the current Z
 * @return
 * 			Current Z
 */
float Car::getZ() {
	return this->position->z;
}

void Car::setColor(Color *c) {

}
