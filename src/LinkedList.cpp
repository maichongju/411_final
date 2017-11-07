#include "LinkedList.hpp"
#include <malloc.h>

Node::Node(int x, int y) {
	this->x = x;
	this->y = y;
	prev = NULL;
	next = NULL;
}

/**
 * Constructor
 */
LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

/**
 * Delete all the node in the linked list and free all the node
 */
LinkedList::~LinkedList() {
	Node *current = this->head;
	if (current != NULL) {
		Node *next = current->next;
		while (next != NULL) {
			delete (current);
			current = next;
			next = next->next;
		}
		delete (current);
		this->head = NULL;
	}
	size = 0;

}

/**
 * Function will determined if the list is empty
 * @return
 * 			true if is empty, false otherwise
 */
bool LinkedList::isEmpty() {
	return this->head == NULL;
}

/**
 * Function will append the data to the end of the list
 * @param x
 * 			x value of the node
 * @param y
 *			y value of the node
 */
void LinkedList::append(int x, int y) {
	Node *n = new Node(x, y);
	if (this->isEmpty()) {
		this->head = n;
	} else {
		Node *temp = this->head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
	}
	size++;
}

/**
 * Function will pop the first item in the list
 */
void LinkedList::pop() {
	if (!this->isEmpty()) {
		if (this->head->next == NULL) {
			delete (this->head);
			this->head = NULL;
		} else {
			Node *n = this->head;
			while (n->next != NULL) {
				n = n->next;
			}
			n->prev->next = n->next;
			delete (n);
		}
		size--;
	}
}

/**
 * Determined if the given coordinate is in the list
 * @param x
 * 			x value need to be compare
 * @param y
 * 			y value need to be compare
 * @return
 * 			true if in, otherwise false
 */
bool LinkedList::init(int x, int y) {
	if (!this->isEmpty()) {
		Node *n = this->head;
		while (n != NULL) {
			if (n->x == x && n->y == y) {
				return true;
			}
			n = n->next;
		}
	}
	return false;
}
