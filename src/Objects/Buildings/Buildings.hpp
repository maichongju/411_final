#ifndef SRC_OBJECTS_BUILDINGS_BUILDINGS_HPP_
#define SRC_OBJECTS_BUILDINGS_BUILDINGS_HPP_

#include "Building.hpp"

extern float GlobalTime;

class BuildingNode {
public:
	BuildingNode(Building *b, int front, int right, int rear, int left);
	Building *b;
	BuildingNode *next;
};

class BuildingList {
public:
	BuildingNode *head;
	BuildingList();
	int size;
	void draw();
	void append(Building *b, int front, int right, int rear, int left);
};

class Buildings {
public:
	Buildings();
	void draw();
private:
	BuildingList *l;
};



#endif
