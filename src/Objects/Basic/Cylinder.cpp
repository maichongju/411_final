#include "Cylinder.hpp"

Cylinder::Cylinder() {
	this->x = this->y = this->z = 0;
	textureID = 3;
	obj = gluNewQuadric();
}
Cylinder::Cylinder(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	textureID = 3;
	obj = gluNewQuadric();
}
Cylinder::Cylinder(float x, float y, float z, int TextureID) {
	this->x = x;
	this->y = y;
	this->z = z;
	textureID = TextureID;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	gluQuadricOrientation(obj, GLU_OUTSIDE);
	gluQuadricNormals(obj, GLU_SMOOTH);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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
	glColor3f(.60, .30, 0);
	glBegin(GL_POLYGON);
	obj = gluNewQuadric();
	gluCylinder(obj, 0.05f, 0.05f, .50f, 32, 32);
	glPopMatrix();
}
void Cylinder::drawtexture() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	translate(this->x, this->y, this->z);
	glColor3f(.60, .30, 0);

	//glBegin(GL_POLYGON);
	obj = gluNewQuadric();
	gluCylinder(obj, 0.05f, 0.05f, .50f, 32, 32);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void Cylinder::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}

