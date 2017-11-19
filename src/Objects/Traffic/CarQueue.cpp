#include "CarQueue.hpp"

CarQueue::CarQueue() {
	front = 0;
	rear = 0;
	size = 0;
}

void CarQueue::push(Car *car) {
	if (isEmpty()) {
		front = car;
		rear = car;
	}
	else {
		rear->next = car;
		car->prev = rear;
		rear = car;
	}
	size++;
}

int CarQueue::Size() {
	return size;
}

bool CarQueue::isEmpty() {
	return size == 0;
}

/**
 * Pop the first item in the queue
 * @return
 * 			first item in the queue
 */
Car *CarQueue::pop() {
	if (!isEmpty()) {
		Car *temp = this->front;
		if (size == 1) {
			this->front = 0;
			this->rear = 0;
		} else {
			this->front = this->front->next;
			this->front->prev = 0;
		}
		size--;
		temp->next = 0;
		return temp;
	}
	printf("\nCan not pop from a Empty Queue\n");
	return 0;
}

Car *CarQueue::peek() {
	if (!isEmpty()) {
		return this->front;
	}
	return 0;
}
