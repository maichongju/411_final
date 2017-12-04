/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	traffic = new Traffic();
	b = new Buildings();
	Env = new Environment();
}

World::~World() {

}

void World::settime(int time) {
	this->Env->setsolar(time);
}

void World::draw_world() {

	traffic->draw();
	b->draw();
	Env->draw();


}

void World::reset() {
	this->~World();

}


