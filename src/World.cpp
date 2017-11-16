/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {

}

World::~World() {

}

void World::draw_world() {

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-100, 0, -100);
	glVertex3f(-100, 0, 100);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glEnd();
	cube.draw();


	this->draw(); // For debug

}

void World::reset() {
	this->~World();

}

void World::draw() {
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(100, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 100, 0);

	glColor3f(0, 0, 1);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 0, -100);
	glEnd();
}

