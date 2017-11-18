#include "Environment.hpp"

Environment::Environment() {
	G = new Ground();
}

void Environment::draw() {
	G->draw();
}

void Environment::reset() {

}

