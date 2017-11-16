#include "Buildings.hpp"

Buildings::Buildings() {
	b = new Building(1, 0, 1);
	b->setBuildingWindows(6, 2, 6, 2);
}

void Buildings::draw() {
	b->draw();
}
