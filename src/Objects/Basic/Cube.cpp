#include "Cube.hpp"

Cube::Cube() {
	/**
	 *
	 *      (1)  S A D B O Y S (3)
	 *         / A         / A
	 *       /   D       /   D
	 * (5) S A D B O Y S (7) B
	 *     A     O     A     O
	 *     D     Y     D     Y
	 *     B (0) S A D B O Y S (2)
	 *     O   /       O   /
	 *     Y /         Y /
	 * (4) S A D B O Y S (6)
	 *
	 *
	 *
	 */
	vertex[0][0] = 0;
	vertex[0][1] = 0;
	vertex[0][2] = 0;

	vertex[1][0] = 0;
	vertex[1][1] = 1;
	vertex[1][2] = 0;

	vertex[2][0] = 1;
	vertex[2][1] = 0;
	vertex[2][2] = 0;

	vertex[3][0] = 1;
	vertex[3][1] = 1;
	vertex[3][2] = 0;

	vertex[4][0] = 0;
	vertex[4][1] = 0;
	vertex[4][2] = 1;

	vertex[5][0] = 0;
	vertex[5][1] = 1;
	vertex[5][2] = 1;

	vertex[6][0] = 1;
	vertex[6][1] = 0;
	vertex[6][2] = 1;

	vertex[7][0] = 1;
	vertex[7][1] = 1;
	vertex[7][2] = 1;

	face[0][0] = 0;
	face[0][1] = 1;
	face[0][2] = 3;
	face[0][3] = 2;

	face[1][0] = 3;
	face[1][1] = 7;
	face[1][2] = 6;
	face[1][3] = 2;

	face[2][0] = 7;
	face[2][1] = 5;
	face[2][2] = 4;
	face[2][3] = 6;

	face[3][0] = 4;
	face[3][1] = 5;
	face[3][2] = 1;
	face[3][3] = 0;

	face[4][0] = 5;
	face[4][1] = 7;
	face[4][2] = 3;
	face[4][3] = 1;

	face[5][0] = 6;
	face[5][1] = 4;
	face[5][2] = 0;
	face[5][3] = 2;

	faceColor[0][0] = 1.0;
	faceColor[0][1] = 0.0;
	faceColor[0][2] = 0.0;

	faceColor[1][0] = 0.0;
	faceColor[1][1] = 1.0;
	faceColor[1][2] = 0.0;

	faceColor[2][0] = 0.0;
	faceColor[2][1] = 0.0;
	faceColor[2][2] = 1.0;

	faceColor[3][0] = 1.0;
	faceColor[3][1] = 1.0;
	faceColor[3][2] = 0.0;

	faceColor[4][0] = 1.0;
	faceColor[4][1] = 0.0;
	faceColor[4][2] = 1.0;

	faceColor[5][0] = 0.0;
	faceColor[5][1] = 1.0;
	faceColor[5][2] = 1.0;

	facetexture[0] = -1;
	facetexture[1] = -1;
	facetexture[2] = -1;
	facetexture[3] = -1;
	facetexture[4] = -1;
	facetexture[5] = -1;
}

/**
 * Function will scale the cube according the x , y and z.
 * @param x
 * 			value need to scale to x (must greater 0)
 * @param y
 * 			value need to scale to y (must greater 0)
 * @param z
 * 			value need to scale to z (must greater 0)
 */
void Cube::scale(float x, float y, float z) {
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
	vertex[6][0] *= x;
	vertex[7][0] *= x;

	vertex[5][1] *= y;
	vertex[7][1] *= y;
	vertex[3][1] *= y;
	vertex[1][1] *= y;

	vertex[5][2] *= z;
	vertex[7][2] *= z;
	vertex[6][2] *= z;
	vertex[4][2] *= z;
}

/**
 * Private Function
 * Draw the ith face for the cube and the outline
 * @param i
 * 			the
 */
void Cube::draw_face(int i) {
	if (facetexture[i] == -1) {
		glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
		glBegin(GL_POLYGON);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
		glVertex3fv(&vertex[face[i][3]][0]);
		glEnd();

		glColor3f(0, 0, 0);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
		glVertex3fv(&vertex[face[i][3]][0]);
		glEnd();
	} else {
		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, facetexture[i]);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3fv(&vertex[face[i][0]][0]);
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(&vertex[face[i][1]][0]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(&vertex[face[i][2]][0]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(&vertex[face[i][3]][0]);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

}

/**
 * Draw function for Cube
 */
void Cube::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 6; i++) {
		draw_face(i);
	}
	glPopMatrix();
}

/**
 * Function will change the ith side color to given color
 * @param i
 * 			number of side face need to be change
 * @param r
 * 			Red for the color (float)
 * @param g
 * 			Green for the color	(float)
 * @param b
 * 			Blue for the color (float)
 */
void Cube::changeFaceColor(int i, float r, float g, float b) {

	faceColor[i][0] = r;
	faceColor[i][1] = g;
	faceColor[i][2] = b;
}

void Cube::setTextureID(int i, int ID) {
	facetexture[i] = ID;
}
