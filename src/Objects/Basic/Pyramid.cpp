#include "Pyramid.hpp"

/**
 *             (4)
 *		        ^
 *             / \
 *            /   \
 * 			 /     \
 *      (0) -----------  (3)
 *         /          /
 *        /          /
 *   (1)  ----------- (2)
 */

Pyramid::Pyramid() {
	TextureID = 0;
	vertex[0][0] = 0;
	vertex[0][1] = 0;
	vertex[0][2] = 0;

	vertex[1][0] = 0;
	vertex[1][1] = 0;
	vertex[1][2] = 1;

	vertex[2][0] = 1;
	vertex[2][1] = 0;
	vertex[2][2] = 1;

	vertex[3][0] = 1;
	vertex[3][1] = 0;
	vertex[3][2] = 0;

	vertex[4][0] = 0.5;
	vertex[4][1] = 0.5;
	vertex[4][2] = 0.5;

	faceColor[0][0] = 1;
	faceColor[0][1] = 0;
	faceColor[0][2] = 0;

	faceColor[1][0] = 0;
	faceColor[1][1] = 1;
	faceColor[1][2] = 0;

	faceColor[2][0] = 0;
	faceColor[2][1] = 0;
	faceColor[2][2] = 1;

	faceColor[3][0] = 1;
	faceColor[3][1] = 1;
	faceColor[3][2] = 0;
	;
	this->setface();
}

void Pyramid::setface() {

	face[0][0] = 0;
	face[0][1] = 1;
	face[0][2] = 4;

	face[1][0] = 1;
	face[1][1] = 2;
	face[1][2] = 4;

	face[2][0] = 2;
	face[2][1] = 3;
	face[2][2] = 4;

	face[3][0] = 0;
	face[3][1] = 3;
	face[3][2] = 4;

}

void Pyramid::drawface(int i) {
	glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
	glBegin(GL_POLYGON);
	glVertex3fv(&vertex[face[i][0]][0]);
	glVertex3fv(&vertex[face[i][1]][0]);
	glVertex3fv(&vertex[face[i][2]][0]);
	glEnd();
}

void Pyramid::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 4; i++) {
		drawface(i);
	}

	glPopMatrix();

}

void Pyramid::drawtexture() {
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 4; i++) {
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3fv(&vertex[face[i][0]][0]);
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(&vertex[face[i][1]][0]);
		glTexCoord2f(0.5, 0.5);
		glVertex3fv(&vertex[face[i][2]][0]);
		glEnd();
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Pyramid::drawtexture(int TextureID) {

	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 4; i++) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3fv(&vertex[face[i][0]][0]);
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(&vertex[face[i][1]][0]);
		glTexCoord2f(0.5, 0.5);
		glVertex3fv(&vertex[face[i][2]][0]);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

}

void Pyramid::scale(float x, float y, float z) {

	if (x <= 0) {
		x = 1;
	}
	if (y <= 0) {
		y = 1;
	}
	if (z <= 0) {
		z = 1;
	}
	vertex[2][0] *= x;
	vertex[3][0] *= x;
	vertex[4][0] *= x;

	vertex[4][1] *= y;

	vertex[1][2] *= z;
	vertex[2][2] *= z;
	vertex[4][2] *= z;

}

void Pyramid::setTextureID(int TextureID) {
	this->TextureID = TextureID;
}
