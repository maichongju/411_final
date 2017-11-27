#include "Cylinder.hpp"

Cylinder::Cylinder() {
	this->x = this->y = this->z = 0;

}
Cylinder::Cylinder(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
//Cylinder::Cylinder(float x, float y, float z) {
//	cylinder = new Cylinder();
//	cylinder->translate(x, y, z);
//	cylinder->rotate(0.0, 1.0, 0.0, 90.0);
//	//this->x = this->y = this->z = 1;
//	position = new Point(x, y, z);
//}

void Cylinder::draw() {
	//glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	translate(this->x, this->y, this->z);
	//this->ctm_multiply();
	glColor3f(.60, .30, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *obj = gluNewQuadric();



	gluCylinder(obj, 0.05f, 0.05f, .50f, 32, 32);
	glPopMatrix();
}
void Cylinder::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}

