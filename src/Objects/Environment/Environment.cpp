#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	T = new tree(0, 0.0, 0, TREE_CONE);
	T2 = new tree(1.0, 0.0, -2.0, TREE_SPHERE);
	T3 = new tree(2.0, 0.0, -2.0, TREE_CUBE);
	solar = new Solar();

}

void Environment::draw() {
	G->draw();
	//T->draw();
	T2->draw();
	//T3->draw();
	solar->draw();
}

void Environment::setsolar(int time) {
	this->solar->settime(time);
}

void Environment::reset() {

}

