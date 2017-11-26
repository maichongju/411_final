#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	T = new Cylinder(2, 2, 2);
	T2 = new Cone();
	solar = new Solar();

}

void Environment::draw() {
	G->draw();
	T->draw();
	T2->draw();
	solar->draw();
}

void Environment::reset() {

}

