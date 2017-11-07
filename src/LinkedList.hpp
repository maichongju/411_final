#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

class Node {
public:
	int x, y;
	Node *next;
	Node *prev;
	Node(int x, int y);
};

class LinkedList {
public:
	int size;
	Node *head;
	LinkedList();
	~LinkedList();
	void append(int x, int y);
	void pop();
	bool isEmpty();
	bool init(int x, int y);

};

#endif
