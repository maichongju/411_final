#include "Cone.hpp"

Cone::Cone() {
	position = new Point(0, 0, 0);
}

void Cone::draw(float x, float y, float z) {
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glTranslated(x, y, z);
	//this->ctm_multiply();
	glColor3f(0, 1, .50);
	glBegin(GL_POLYGON);
	GLUquadricObj *obj = gluNewQuadric();

	gluCylinder(obj, 0.1f, 0.0f, .50f, 32, 32);
	glPopMatrix();

}
