#include "Cone.hpp"

Cone::Cone() {
	this->x = this->y = this->z = 0;
	//position = new Point(0, 0, 0);
}
Cone::Cone(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	//position = new Point(p->x, p->y, p->z);
}
void Cone::draw() {
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	//glTranslatef(position->x, position->y, position->z);
	translate(this->x, this->y, this->z);
	//this->ctm_multiply();
	glColor3f(.30, .80, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *obj = gluNewQuadric();

	gluCylinder(obj, 0.1f, 0.0f, .50f, 32, 32);
	glPopMatrix();

}
void Cone::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}

//void Cone::translate(float x, float y, float z) {
//	position->x += x;
//	position->y += y;
//	position->z += z;
//}
