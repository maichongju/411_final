#include "Buildings.hpp"

Buildings::Buildings() {
	b = new Building(0.4, 0, 0.4);
	b->setBuildingWindows(6, 2, 6, 2);

}

void Buildings::draw() {
	b->draw();
}
