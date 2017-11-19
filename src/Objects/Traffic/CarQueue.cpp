#include "CarQueue.hpp"

CarQueue::CarQueue() {
	front = 0;
	rear = 0;
	size = 0;
}

/**
 * Push the given Car Object to the end of the queue
 * @param car
 * 			Given car object need to push into queue
 */
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

/**
 * Size of the current queue
 * @return
 * 			The size of the current queue
 */
int CarQueue::Size() {
	return size;
}

/**
 * Check if the queue is empty
 * @return
 * 			true if is Empty, otherwise false
 */
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

/**
 * Peek the front for the current queue
 * @return
 * 			The front Car Object in the current queue
 */
Car *CarQueue::peek() {
	if (!isEmpty()) {
		return this->front;
	}
	return 0;
}

/**
 * Function will remove and free the last node in the list
 */
void CarQueue::removeRear() {
	if (!this->isEmpty()) {
		Car *temp = this->rear;
		if (size == 1) {
			this->front = 0;
			this->rear = 0;
		} else {
			this->rear->prev->next = 0;
		}
		size--;
		delete temp;
	}
}
