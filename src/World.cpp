/**
 * File: World.hpp
 */

#include "World.hpp"
#include "Pyramid.hpp"
#include "House.hpp"

World::World() {

}

World::~World() {

}

void World::draw_world() {

	this->draw();

}

void World::reset() {
	this->~World();

}

void World::draw() {
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 0, 1);
	glEnd();
}
