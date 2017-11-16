#include "Cylinder.hpp"

Cylinder::Cylinder() {
	position = new Point(0, 0, 0);
}

void Cylinder::draw() {
	glColor3f(1, 0, 0);
	gluCylinder(QOBJ, 1.0, 1.0, 0.4, 1, 16);
	glutPostRedisplay();
}
