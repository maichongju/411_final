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
	/////
	l = new BuildingList();
	Building *na = new Building(0.41, 0, 0.41);
	Building *n2a = new Building(.41, 0, 0.41 + .5);
	Building *n3a = new Building(.41, 0, 0.41 + 1);
	Building *n4a = new Building(.41, 0, 0.41 + 1.5);
	Building *nb = new Building(.41 + .7, 0, .41);
	Building *n2b = new Building(.41 + 1.4, 0, .41);
	Building *n3b = new Building(.41 + 2.07, 0, .41);
	Building *nc = new Building(.41 + .7, 0, .41 + .5);
	Building *n2c = new Building(.41 + 1.4, 0, .41 + .5);
	Building *n3c = new Building(.41 + 2.07, 0, .41 + .5);
	Building *nd = new Building(.41 + .7, 0, .41 + 1);
	Building *n2d = new Building(.41 + 1.4, 0, .41 + 1);
	Building *n3d = new Building(.41 + 2.07, 0, .41 + 1);
	Building *ne = new Building(.41 + .7, 0, .41 + 1.5);
	Building *n2e = new Building(.41 + 1.4, 0, .41 + 1.5);
	Building *n3e = new Building(.41 + 2.07, 0, .41 + 1.5);
	na->setwalltexture(TEXTURE_BUILDING1);
	n2a->setwalltexture(TEXTURE_BUILDING2);
	n3a->setwalltexture(TEXTURE_BUILDING4);
	n4a->setwalltexture(TEXTURE_BUILDING3);
	nb->setwalltexture(TEXTURE_BUILDING1);
	n2b->setwalltexture(TEXTURE_BUILDING4);
	n3b->setwalltexture(TEXTURE_BUILDING1);
	nc->setwalltexture(TEXTURE_BUILDING4);
	n2c->setwalltexture(TEXTURE_BUILDING3);
	n3c->setwalltexture(TEXTURE_BUILDING4);
	nd->setwalltexture(TEXTURE_BUILDING2);
	n2d->setwalltexture(TEXTURE_BUILDING3);
	n3d->setwalltexture(TEXTURE_BUILDING1);
	ne->setwalltexture(TEXTURE_BUILDING3);
	n2e->setwalltexture(TEXTURE_BUILDING4);
	n3e->setwalltexture(TEXTURE_BUILDING2);
	l->append(na, 6, 2, 6, 2);
	l->append(n2a, 6, 2, 6, 2);
	l->append(n3a, 6, 2, 6, 2);
	l->append(n4a, 6, 2, 6, 2);
	l->append(nb, 6, 2, 6, 2);
	l->append(n2b, 6, 2, 6, 2);
	l->append(n3b, 6, 2, 6, 2);
	l->append(nc, 6, 2, 6, 2);
	l->append(n2c, 6, 2, 6, 2);
	l->append(n3c, 6, 2, 6, 2);
	l->append(nd, 6, 2, 6, 2);
	l->append(n2d, 6, 2, 6, 2);
	l->append(n3d, 6, 2, 6, 2);
	l->append(ne, 6, 2, 6, 2);
	l->append(n2e, 6, 2, 6, 2);
	l->append(n3e, 6, 2, 6, 2);
	/////
	Building *nn = new Building(-0.9, 0, 0.41);
	Building *nn2 = new Building(-2, 0, 0.41 + .4);
	Building *nn2a = new Building(-2, 0, 0.41 + 1.2);
	Building *nn2b = new Building(-2, 0, 0.41 + 2);
	Building *nn2c = new Building(-3, 0, 0.41 + .4);
	Building *nn2d = new Building(-3, 0, 0.41 + 1.2);
	Building *nn2e = new Building(-3, 0, 0.41 + 2);
	Building *nn3 = new Building(-.9, 0, 1.2);
	Building *nn4 = new Building(-.9, 0, 2);

	nn->setwalltexture(TEXTURE_BUILDING1);
	nn2->setwalltexture(TEXTURE_BUILDING2);
	nn3->setwalltexture(TEXTURE_BUILDING3);
	nn4->setwalltexture(TEXTURE_BUILDING4);
	nn2a->setwalltexture(TEXTURE_BUILDING3);
	nn2b->setwalltexture(TEXTURE_BUILDING4);
	nn2c->setwalltexture(TEXTURE_BUILDING4);
	nn2d->setwalltexture(TEXTURE_BUILDING3);
	nn2e->setwalltexture(TEXTURE_BUILDING4);


	l->append(nn, 6, 2, 6, 2);
	l->append(nn2, 6, 2, 6, 2);
	l->append(nn3, 6, 2, 6, 2);
	l->append(nn4, 6, 2, 6, 2);
	l->append(nn2a, 6, 2, 6, 2);
	l->append(nn2b, 6, 2, 6, 2);
	l->append(nn2c, 6, 2, 6, 2);
	l->append(nn2d, 6, 2, 6, 2);
	l->append(nn2e, 6, 2, 6, 2);
//	b = new Building(0.4, 0, 0.4);
//	b->setBuildingWindows(6, 2, 6, 2);
//	b2 = new Building(0.5, 0, 0.5);
//	b2->setBuildingWindows(6, 2, 6, 2);

}

void Buildings::draw() {
	l->draw();
}
