#include "Car.hpp"

Car::Car(Point *p, int Facing) {
	position = new Point(p->x, p->y, p->z);
	Moving = false;
	Speed = 0.005;
	this->Facing = Facing;
	Body = new Cube();
	Body->scale(0.3, 0.15, 0.2);
	Body->rotate(0, 1, 0, Facing);
	Body->translate(p->x, p->y + 0.02, p->z + 0.1);

	setWheels();
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
		break;
	}
	case CAR_WEST: {
		Body->translate(-Speed, 0, 0);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(-Speed, 0, 0);
		}
		break;
	}
	case CAR_NORTH: {
		Body->translate(0, 0, -Speed);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(0, 0, -Speed);
		}
		break;
	}
	case CAR_SOUTH: {
		Body->translate(0, 0, Speed);
		for (i = 0; i < 4; i++) {
			Wheels[i]->translate(0, 0, Speed);
		}
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


void reset() {

}
