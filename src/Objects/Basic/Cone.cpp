#include "Cone.hpp"

Cone::Cone() {
	this->x = this->y = this->z = 0;
	this->a = this->b = this->c = 1;
	textureID = 3;
	obj = gluNewQuadric();
	//position = new Point(0, 0, 0);
}
Cone::Cone(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = this->b = this->c = 1;
	textureID = 3;
	obj = gluNewQuadric();
	//position = new Point(p->x, p->y, p->z);
}
Cone::Cone(float x, float y, float z, int TextureID) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = this->b = this->c = 1;
	textureID = TextureID;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	gluQuadricOrientation(obj, GLU_OUTSIDE);
	gluQuadricNormals(obj, GLU_SMOOTH);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}
void Cone::drawtexture() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	/////////

	//////////
	glPushMatrix();
	//glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	translate(this->x, this->y, this->z);
	glColor3f(1, 1, 1);
	glScaled(this->a, this->b, this->c);
	//glScaled(.5, .5, .5);

	//glBegin(GL_POLYGON);
	//gluCylinder(obj, 0.05f, 0.05f, .50f, 32, 32);
	glBegin( GL_QUAD_STRIP);
	float PI = 3.141592654f;
	float nslice = 32;
	float t = 0.;
	float dt = 2 * PI / nslice;
	for (int j = 0; j <= nslice; ++j) {
		glTexCoord2f(t / (2 * PI), 1.);
		glVertex3f(0, 2.5, 0);
		glTexCoord2f(t / (2.5 * PI), 0.);
		glVertex3f(cos(t), 0., -sin(t));
		t = t + dt;
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
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
	this->x = x;
	this->y = y;
	this->z = z;
	glTranslatef(x, y, z);
}
void Cone::scale(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
	glScaled(a, b, c);
}

//void Cone::translate(float x, float y, float z) {
//	position->x += x;
//	position->y += y;
//	position->z += z;
//}
