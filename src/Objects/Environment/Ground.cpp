#include "Ground.hpp"

Ground::Ground() {
}

void Ground::draw() {
	Floor();
	Road();
}


void Ground::Floor() {
	glColor3f(0, 0.5, 0);
	glBegin (GL_POLYGON);
	glVertex3f(-MAP_SIZE_WIDTH, -0.001, -MAP_SIZE_WIDTH);
	glVertex3f(-MAP_SIZE_WIDTH, -0.001, MAP_SIZE_WIDTH);
	glVertex3f(MAP_SIZE_WIDTH, -0.001, MAP_SIZE_WIDTH);
	glVertex3f(MAP_SIZE_WIDTH, -0.001, -MAP_SIZE_WIDTH);
	glEnd();

}

void Ground::Road() {
	// Car size 0.2
	//Horizontal
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-MAP_SIZE_WIDTH, 0, 0.4);
	glVertex3f(MAP_SIZE_WIDTH, 0, 0.4);
	glVertex3f(MAP_SIZE_WIDTH, 0, -0.4);
	glVertex3f(-MAP_SIZE_WIDTH, 0, -0.4);
	glEnd();

	// Vertical
	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0, MAP_SIZE_HEIGHT);
	glVertex3f(0.4, 0, MAP_SIZE_HEIGHT);
	glVertex3f(0.4, 0, -MAP_SIZE_HEIGHT);
	glVertex3f(-0.4, 0, -MAP_SIZE_HEIGHT);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0.4, 0.001, -0.01);
	glVertex3f(0.4, 0.001, 0.01);
	glVertex3f(MAP_SIZE_WIDTH, 0.001, 0.01);
	glVertex3f(MAP_SIZE_WIDTH, 0.001, -0.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.4, 0.001, 0);
	glVertex3f(0.4 + 0.02, 0.001, 0);
	glVertex3f(0.4 + 0.02, 0.001, -0.4);
	glVertex3f(0.4, 0.001, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0.001, 0.01);
	glVertex3f(-0.4, 0.001, -0.01);
	glVertex3f(-MAP_SIZE_WIDTH, 0.001, -0.01);
	glVertex3f(-MAP_SIZE_WIDTH, 0.001, 0.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0.001, 0);
	glVertex3f(-0.4 - 0.02, 0.001, 0);
	glVertex3f(-0.4 - 0.02, 0.001, 0.4);
	glVertex3f(-0.4, 0.001, 0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, 0.001, -MAP_SIZE_HEIGHT);
	glVertex3f(-0.01, 0.001, -MAP_SIZE_HEIGHT);
	glVertex3f(-0.01, 0.001, -0.4);
	glVertex3f(0.01, 0.001, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 0.001, -0.4 - 0.02);
	glVertex3f(-0.4, 0.001, -0.4 - 0.02);
	glVertex3f(-0.4, 0.001, -0.4);
	glVertex3f(0, 0.001, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, 0.001, 0.4);
	glVertex3f(-0.01, 0.001, 0.4);
	glVertex3f(-0.01, 0.001, MAP_SIZE_HEIGHT);
	glVertex3f(0.01, 0.001, MAP_SIZE_HEIGHT);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.4, 0.001, 0.4);
	glVertex3f(0, 0.001, 0.4);
	glVertex3f(0, 0.001, 0.4 + 0.02);
	glVertex3f(0.4, 0.001, 0.4 + 0.02);
	glEnd();

}
