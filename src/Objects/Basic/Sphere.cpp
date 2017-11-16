#include "Sphere.hpp"
#include <stdio.h>

Sphere::Sphere() {
	position.x = 0.0, position.y = 0.0, position.z = 0.0;
	red = 1.0, green = 1.0, blue = 1.0, alpha = 1;
	radius = 0.5;
	soild = true;
	xrotate = 0, yrotate = 0, zrotate = 0;
}

Sphere::Sphere(GLfloat x, GLfloat y, GLfloat z, float r, float g, float b,
		bool s) {
	position.x = x, position.y = y, position.z = z;
	red = r, green = g, blue = b, alpha = 1;
	radius = 0.5;
	soild = s;
	xrotate = 0, yrotate = 0, zrotate = 0;
}

void Sphere::translate(GLfloat x, GLfloat y, GLfloat z) {
	position.x += x;
	position.y += y;
	position.z += z;
}

void Sphere::rotate_mc(GLfloat x, GLfloat y, GLfloat z, GLfloat angle) {
	xrotate += x * angle;
	yrotate += y * angle;
	zrotate += z * angle;

}

void Sphere::setColor(float r, float g, float b, float a) {
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

void Sphere::scale(float s) {
	radius += s;
}
void Sphere::rotate_wc(GLfloat x, GLfloat y, GLfloat z, GLfloat angle) {
	angle = angle * 3.1415926 / 180;

	Point temp = position;
	if (y == 1) {
		position.x = temp.z * sin(angle) + temp.x * cos(angle);
		position.z = temp.z * cos(angle) - temp.x * sin(angle);
	} else if (x == 1) {
		position.y = temp.y * cos(angle) - temp.z * sin(angle);
		position.z = temp.y * sin(angle) + temp.z * cos(angle);
	} else if (z == 1) {
		position.x = temp.x * cos(angle) - temp.y * sin(angle);
		position.y = temp.x * sin(angle) + temp.y * cos(angle);
	}
}
void Sphere::draw() {
	glPushMatrix();
	glColor4f(red, green, blue, alpha);
	glRotatef(xrotate, 1.0, 0, 0);
	glRotatef(yrotate, 0, 1.0, 0);
	glRotatef(zrotate, 0, 0, 1.0);
	glTranslatef(position.x, position.y, position.z);
	if (soild) {
		glutSolidSphere(radius, 30, 30);
	} else {
		glutWireSphere(radius, 30, 30);
	}
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}
