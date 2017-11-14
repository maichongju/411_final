/*
 *	CP411 Assignment 2
 *  Chongju Mai
 *  maix3820@mylaurier.ca
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "World.hpp"
#include "Camera.hpp"
#include "mesh.hpp"

GLint winWidth = 800, winHeight = 800;

GLfloat red = 1.0, green = 1.0, blue = 1.0;  //color
GLint moving = 0, xBegin = 0, type = 4, selected;
GLint mode = 0;  //0 for doing nothing 1 MC 2 WC 3 VC
GLint objtype = 0; // Type of current object. 0 Cube 1 Pyramid 2 house
//Declare a world containing all objects to draw.
World myWorld;
Camera myCamera;

void printmac() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f ", myWorld.list[0]->getMC().mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	glColor3f(red, green, blue);
	myWorld.draw_world(); // draw all objects in the world
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseAction(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		moving = 1;
		xBegin = x;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		moving = 0;
	}
}

void mouseMotion(GLint x, GLint y) {

	GLfloat rx, ry, rz, theta;
	if (moving) {
		if (mode == 1) {
			switch (type) {
			case 1: {
				theta = (xBegin - x > 0) ? 1 : -1;
				rx = myWorld.list[objtype]->getMC().mat[0][0];
				ry = myWorld.list[objtype]->getMC().mat[1][0];
				rz = myWorld.list[objtype]->getMC().mat[2][0];
				myWorld.list[objtype]->rotate_mc(rx, ry, rz, theta * 0.5);
			}
				break;
			case 2: {
				theta = (xBegin - x > 0) ? 1 : -1;
				rx = myWorld.list[objtype]->getMC().mat[0][1];
				ry = myWorld.list[objtype]->getMC().mat[1][1];
				rz = myWorld.list[objtype]->getMC().mat[2][1];
				myWorld.list[objtype]->rotate_mc(rx, ry, rz, theta * 0.5);
			}
				break;
			case 3: {
				theta = (xBegin - x > 0) ? 1 : -1;
				rx = myWorld.list[objtype]->getMC().mat[0][2];
				ry = myWorld.list[objtype]->getMC().mat[1][2];
				rz = myWorld.list[objtype]->getMC().mat[2][2];
				myWorld.list[objtype]->rotate_mc(rx, ry, rz, theta * 0.5);
			}
				break;
			case 4: {
				theta = (xBegin - x < 0) ? 1 : -1;
				myWorld.list[objtype]->scale_change(theta * 0.005);
				xBegin = x;
			}
				break;
			}
		} else if (mode == 2) {
			switch (type) {
			case 1: { // Rotate x
				theta = (xBegin - x > 0) ? 1 : -1;
				myWorld.list[objtype]->rotate(1, 0, 0, theta * 0.5);
			}
				break;
			case 2: { // Rotate y
				theta = (xBegin - x > 0) ? 1 : -1;
				myWorld.list[objtype]->rotate(0, 1, 0, theta * 0.5);
			}
				break;
			case 3: { // Rotate z
				theta = (xBegin - x > 0) ? 1 : -1;
				myWorld.list[objtype]->rotate(0, 0, 1, theta * 0.5);
			}
				break;
			case 4: { // Translate x
				theta = (xBegin - x < 0) ? 1 : -1;
				myWorld.list[objtype]->translate(theta * 0.005, 0, 0);
			}
				break;
			case 5: { // Translate y
				theta = (xBegin - x < 0) ? 1 : -1;
				myWorld.list[objtype]->translate(0, theta * 0.005, 0);
			}
				break;
			case 6: { // Translate z
				theta = (xBegin - x < 0) ? 1 : -1;
				myWorld.list[objtype]->translate(0, 0, theta * 0.005);
			}
				break;
			}

		} else if (mode == 3) {
			switch (type) {
			case 1: { // Rotate x
				myCamera.rotate(1, 0, 0, 1);
			}
				break;
			case 2: { // Rotate y

				myCamera.rotate(0, 1, 0, 1);
			}
				break;
			case 3: { // Rotate z

				myCamera.rotate(0, 0, 1, 1);
			}
				break;
			case 4: { // Translate x
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.translate(theta * 0.05, 0, 0);
			}
				break;
			case 5: { // Translate y
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.translate(0, theta * 0.05, 0);
			}
				break;
			case 6: { // Translate z
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.translate(0, 0, theta * 0.05);
			}
				break;
			case 7: { // Clipping Near
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.clipnear(theta * 0.02);
				xBegin = x;
			}
				break;
			case 8: { // Clipping Far
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.clipfar(theta * 0.02);
				xBegin = x;
			}
				break;
			case 9: { // Angle
				theta = (xBegin - x < 0) ? 1 : -1;
				myCamera.angle(theta * 0.05);
				xBegin = x;

			}
				break;
			}
		}
	}
	glutPostRedisplay();

}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // Set display-window color to black
	myCamera.setProjectionMatrix();

}

void MCTransMenu(GLint transOption) {
	switch (transOption) {
	case 1: {  //Rotate x
		mode = 1;
		type = 1;
	}
		break;
	case 2: { //Rotate y
		mode = 1;
		type = 2;
	}
		break;
	case 3: { // Rotate z
		mode = 1;
		type = 3;
	}
		break;
	case 4: { //Scale
		mode = 1;
		type = 4;
	}
		break;
	}
	glutPostRedisplay();
}

void WCTransMenu(GLint transOption) {
	switch (transOption) {
	case 1: { // Rotate x
		mode = 2;
		type = 1;
	}
		break;
	case 2: { // Rotate y
		mode = 2;
		type = 2;
	}
		break;
	case 3: { // Rotate z
		mode = 2;
		type = 3;
	}
		break;

	case 4: { // Translate x
		mode = 2;
		type = 4;
	}
		break;
	case 5: { // Translate y
		mode = 2;
		type = 5;
	}
		break;
	case 6: { // Translate z
		mode = 2;
		type = 6;
	}
	}
	glutPostRedisplay();
}

void VCTransMenu(GLint transOption) {
	mode = 3;
	type = transOption;
	glutPostRedisplay();
}

void mainMenu(GLint option) {
	switch (option) {
	case (1): {  // Reset
		red = 1.0;
		green = 1.0;
		blue = 1.0;
		mode = 0;
		myWorld.reset(); // Reset world object
		myCamera.setDefaultCamera();

		break;
	}
	case (2): {
		exit(0);
	}
	}
	glutPostRedisplay();
}

void menu() {

	GLint VCTrans_Menu = glutCreateMenu(VCTransMenu);
	glutAddMenuEntry(" Rotate x ", 1);
	glutAddMenuEntry(" Rotate y ", 2);
	glutAddMenuEntry(" Rotate z", 3);
	glutAddMenuEntry(" Translate x ", 4);
	glutAddMenuEntry(" Translate y ", 5);
	glutAddMenuEntry(" Translate z", 6);
	glutAddMenuEntry(" Clipping Near ", 7);
	glutAddMenuEntry(" Clipping Far ", 8);
	glutAddMenuEntry(" Angle ", 9);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" View Transformations ", VCTrans_Menu);
	glutAddMenuEntry(" Quit", 2);
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CP411 A2 by Chongju Mai");
	init();
	menu();

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
