#include "Buildings.hpp"

Buildings::Buildings() {
	b = new Building();
}

void Buildings::draw() {
	b->draw();
}
