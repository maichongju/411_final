#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	T = new Tree(0, 0.0, 0, TREE_CONE);
	T2 = new Tree(1.0, 0.0, -2.0, TREE_SPHERE);
	T3 = new Tree(2.0, 0.0, -2.0, TREE_CUBE);
	solar = new Solar();
	p = new Pyramid();
	p->translate(0,1,0);

}

void Environment::draw() {
	G->draw();
	T->draw();
	T2->draw();
	T3->draw();
	solar->draw();
	p->draw();
}

void Environment::setsolar(int time) {
	this->solar->settime(time);
}

void Environment::reset() {

}

