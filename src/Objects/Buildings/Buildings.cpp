#include "Buildings.hpp"

Buildings::Buildings() {
	b = new Building(0.4, 0, 0.4);
	b->setBuildingWindows(6, 2, 6, 2);
	//b2= new Building(0.5,0,0.5);
	//b2->setBuildingWindows(6,2,6,2);

}

void Buildings::draw() {
	b->draw();
	//b2->draw();
}
