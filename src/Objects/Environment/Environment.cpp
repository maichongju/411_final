#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	T = new Tree(0, 0.0, 0, TREE_CONE);
	T2 = new Tree(1.0, 0.0, -2.0, TREE_SPHERE);
	//T3 = new Tree(2.0, 0.0, -2.0, TREE_CUBE);
	solar = new Solar();
	mountain = new Mountain(-2.8,0,-2.8);
	mountain->scale(1.3);
	mountain->setTextureID(TEXTURE_PYRAMID);

}

void Environment::draw() {
	G->draw();
	T->draw();
	T2->draw();
	//T3->draw();
	solar->draw();
	mountain->draw();
}

void Environment::setsolar(int time) {
	this->solar->settime(time);
}

void Environment::reset() {

}

