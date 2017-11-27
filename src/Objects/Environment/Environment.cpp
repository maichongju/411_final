#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	T = new tree();
	T2 = new tree();
	T3 = new tree();
	solar = new Solar();

}

void Environment::draw() {
	G->draw();
	T->draw(1, 1, 0, CONE_TREE);
	T2->draw(1, 2, 0, CUBE_TREE);
	T3->draw(2, 2, 0, SPHERE_TREE);
	solar->draw();
}

void Environment::reset() {

}

