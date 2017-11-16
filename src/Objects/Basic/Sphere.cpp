#include "Sphere.hpp"

Sphere::Sphere(Point *p, Color *c, float r) {
	this->translate(p->x, p->y, p->z);
	color = new Color(c->red, c->green, c->blue, c->alpha);
	radius = r;
}
void Sphere::draw() {
	glPushMatrix();
	glColor3f(color->red, color->green, color->blue);
	this->ctm_multiply();
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}

void Sphere::draw(Color *color, Point *p) {
	glPushMatrix();
	glColor3f(color->red, color->green, color->blue);
	this->ctm_multiply();
	//glTranslatef(p->x, p->y, p->z);
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}


