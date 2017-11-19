#ifndef SRC_OBJECTS_TRAFFIC_CARQUEUE_HPP_
#define SRC_OBJECTS_TRAFFIC_CARQUEUE_HPP_
#include "Car.hpp"
#include <stdio.h>

class CarQueue {
public:

	Car *front, *rear;
	CarQueue();
	void push(Car *car);
	//Car *get(int index);
	Car *pop();
	Car *peek();
	bool isEmpty();
	int Size();
private:
	int size;
};

#endif /* SRC_OBJECTS_TRAFFIC_CARQUEUE_HPP_ */
