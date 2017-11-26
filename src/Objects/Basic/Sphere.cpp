#include "Sphere.hpp"

Sphere::Sphere(Point *p, Color *c, float r) {
	this->translate(p->x, p->y, p->z);
	color = new Color(c->red, c->green, c->blue, c->alpha);
	textureID = 0;
	radius = r;
	quad = gluNewQuadric();

	gluQuadricTexture(quad, GL_TRUE);
	gluQuadricOrientation(quad, GLU_OUTSIDE);
	gluQuadricNormals(quad, GLU_SMOOTH);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

Sphere::Sphere(Point *p, int TextureID, float r) {
	this->translate(p->x, p->y, p->z);
	color = new Color(1, 1, 1, 1);
	radius = r;
	textureID = TextureID;
	quad = gluNewQuadric();

	gluQuadricTexture(quad, GL_TRUE);
	gluQuadricOrientation(quad, GLU_OUTSIDE);
	gluQuadricNormals(quad, GLU_SMOOTH);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}

void Sphere::drawtexture() {
	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glPushMatrix();
	this->ctm_multiply();
	gluSphere(quad, radius, 30, 30);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

