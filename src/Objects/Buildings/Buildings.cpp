#include "Buildings.hpp"

BuildingNode::BuildingNode(Building *b, int front, int right, int rear,
		int left) {
	b->setBuildingWindows(front, right, rear, left);
	this->b = b;

	next = NULL;
}

BuildingList::BuildingList() {
	this->head = NULL;
	size = 0;
}

void BuildingList::append(Building *b, int front, int right, int rear,
		int left) {
	BuildingNode *n = new BuildingNode(b, front, right, rear, left);
	BuildingNode *current;

	if (size == 0) {
		this->head = n;
	} else {

		for (current = this->head; current->next != NULL;
				current = current->next) {
		}
		current->next = n;
	}
	size++;
}

void BuildingList::draw() {
	if (size != 0) {
		BuildingNode *n;
		for (n = this->head; n != NULL; n = n->next) {
			n->b->draw();
		}
	}
}

Buildings::Buildings() {
	l = new BuildingList();
	Building *n = new Building(0.41, 0, 0.41);
	n->setwalltexture(TEXTURE_BUILDING1);
	l->append(n, 6, 2, 6, 2);

//	b = new Building(0.4, 0, 0.4);
//	b->setBuildingWindows(6, 2, 6, 2);
//	b2 = new Building(0.5, 0, 0.5);
//	b2->setBuildingWindows(6, 2, 6, 2);

}

void Buildings::draw() {
	l->draw();
}
