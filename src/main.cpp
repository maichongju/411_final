/*
 *	CP411 Assignment 2
 *  Chongju Mai
 *  maix3820@mylaurier.ca
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Constant.hpp"
#include "World.hpp"
#include "Camera.hpp"

GLint winx = 100, winy = 100;

GLint moving = 0, xBegin = 0, type = 4, selected;
GLint mode = 0;  //0 for doing nothing 1 MC 2 WC 3 VC
GLint objtype = 0; // Type of current object. 0 Cube 1 Pyramid 2 house
//Declare a world containing all objects to draw.
World myWorld;
Camera myCamera;

/**
 * Function will set the windows to the center of the screen according screen resolution
 * if screen_height or screen_width means the resolution cannot get correctly, then the
 * function will not change the default value for window create position
 * @param screen_height
 * 			the height of the current screen, 0 means resolution unavailable
 * @param screen_width
 * 			the width of the current screen, 0 means resolution unavailable
 */
void centerwindow(int screen_height, int screen_width) {
	if (screen_height != 0 && screen_width != 0) {
		winx = screen_width / 2 - WIN_WIDTH / 2;
		winy = screen_height / 2 - WIN_HEIGHT / 2;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw_world(); // draw all objects in the world
	glFlush();
	glutSwapBuffers();
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

/**
 * Function for mouse motion
 * @param x
 * @param y
 */
void mouseMotion(GLint x, GLint y) {

	GLfloat theta;
	if (moving) {
		if (mode == 3) {
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
	glClearColor(0.0, 0, 0, 1.0); // Set display-window color deep sky blue
	myCamera.setProjectionMatrix();

}

void VCTransMenu(GLint transOption) {
	mode = 3;
	type = transOption;
	glutPostRedisplay();
}

void mainMenu(GLint option) {
	switch (option) {
	case (1): {  // Reset
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

	// For debug propose, will be delete
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
	centerwindow(glutGet(GLUT_SCREEN_HEIGHT), glutGet(GLUT_SCREEN_WIDTH));
	glutInitWindowPosition(winx, winy);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow (WIN_TITLE);
	init();
	menu();

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
