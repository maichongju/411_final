#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "Texture/RGBpixmap.h"
#include "Constant.hpp"
#include "World.hpp"
#include "Camera.hpp"

float GlobalTime = 7;
GLUquadric* QOBJ;

float IdleTime = 0;
GLint winx = 100, winy = 100;

GLint moving = 0, xBegin = 0, type = 4, selected;
GLint mode = 0;  //0 for doing nothing 1 MC 2 WC 3 VC
GLint objtype = 0; // Type of current object. 0 Cube 1 Pyramid 2 house
//Declare a world containing all objects to draw.
World myWorld;
Camera myCamera;
Color *SkyColor;
RGBpixmap texture[10];
/**
 * Function for Idle
 */
static int oldTime, newTime;
void idleFunc(void) {
	GLfloat speed = 0.0005;
	oldTime = clock();
	IdleTime = (newTime - oldTime) * speed;
	GlobalTime += GLOBAL_TIME;
	if (GlobalTime > 24) {
		GlobalTime = 0;
	}
	newTime = clock();
	oldTime = newTime;
	glutPostRedisplay();
	//printf("%f\n", SOLAR_ROTATE);
}

/**
 * Function will set up all the texture need to be use
 */
void setTexture() {
	texture[TEXTURE_SUN].readBMPFile("Img/sun.bmp");
	texture[TEXTURE_SUN].setTexture(TEXTURE_SUN);
	texture[TEXTURE_MOON].readBMPFile("Img/moon.bmp");
	texture[TEXTURE_MOON].setTexture(TEXTURE_MOON);
	texture[TEXTURE_TREE_BARK].readBMPFile("Img/tree_bark.bmp");
	texture[TEXTURE_TREE_BARK].setTexture(TEXTURE_TREE_BARK);
	texture[TEXTURE_LEAF].readBMPFile("Img/tree_leaf.bmp");
	texture[TEXTURE_LEAF].setTexture(TEXTURE_LEAF);

	texture[TEXTURE_BUILDING1].readBMPFile("Img/Building1.bmp");
	texture[TEXTURE_BUILDING1].setTexture(TEXTURE_BUILDING1);
	texture[TEXTURE_BUILDING2].readBMPFile("Img/Building2.bmp");
	texture[TEXTURE_BUILDING2].setTexture(TEXTURE_BUILDING2);
	texture[TEXTURE_BUILDING3].readBMPFile("Img/Building3.bmp");
	texture[TEXTURE_BUILDING3].setTexture(TEXTURE_BUILDING3);
	texture[TEXTURE_BUILDING4].readBMPFile("Img/Building4.bmp");
	texture[TEXTURE_BUILDING4].setTexture(TEXTURE_BUILDING4);
	texture[TEXTURE_BUILDING5].readBMPFile("Img/Building5.bmp");
	texture[TEXTURE_BUILDING5].setTexture(TEXTURE_BUILDING5);

	texture[TEXTURE_PYRAMID].readBMPFile("Img/Pyramid.bmp");
	texture[TEXTURE_PYRAMID].setTexture(TEXTURE_PYRAMID);
}

/**
 * Function will take the GlobalTime and fade the sky color
 */
static int colorcount;
void dayColor() {
	if (GlobalTime > 6 && GlobalTime < 9) {
		colorcount += 1;
		if (colorcount == 11) {
			SkyColor->SkyfadeIn();
			colorcount = 0;
		}
	} else if (GlobalTime > 18 && GlobalTime < 21) {
		colorcount += 1;
		if (colorcount == 11) {
			SkyColor->SkyfadeOut();
			colorcount = 0;
		}
	} else {
		if (colorcount != 0) {
			colorcount = 0;
		}
	}
}
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

/**
 * Function for display
 */
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	dayColor();
	glClearColor(SkyColor->red, SkyColor->green, SkyColor->blue,
			SkyColor->alpha); // Set display-window color deep sky blue
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
static int X = -1, Y = -1;
void passivemouseFunc(int x, int y) {
	if (X != -1) {
		int tx = X - x;
		int ty = Y - y;
		if (tx > 0) {
			myCamera.turn(CAMERA_TURN_LEFT);
		} else if (tx < 0) {
			myCamera.turn(CAMERA_TURN_RIGHT);
		}
		if (ty > 0) {
			myCamera.refupdown(CAMERA_UP);
		} else if (ty < 0) {
			myCamera.refupdown(CAMERA_DOWN);
		}

	}
	X = x;
	Y = y;
	//printf("%d,%d\n", x, y);
}


void init(void) {
	SkyColor = new Color(0.67, 0.93, 0.93, 0.5);
	QOBJ = gluNewQuadric();
	gluQuadricNormals(QOBJ, GLU_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	myCamera.setProjectionMatrix();
	glCullFace(GL_BACK);
	glEnable( GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}

/**
 * Function for keyboard
 * @param key
 * @param x
 * @param y
 */
void keyboardFunc(unsigned char key, int x, int y) {
	if (key == 'w' || key == 'W') {
		myCamera.move(CAMERA_MOVE_FORWARD);
	} else if (key == 's' || key == 'S') {
		myCamera.move(CAMERA_MOVE_BACKWARD);
	} else if (key == 'd' || key == 'D') {
		myCamera.turn(CAMERA_TURN_RIGHT);
	} else if (key == 'a' || key == 'A') {
		myCamera.turn(CAMERA_TURN_LEFT);
	} else if (key == 'z' || key == 'Z') {
		myCamera.eyeupdown(CAMERA_UP);
	} else if (key == 'x' || key == 'X') {
		myCamera.eyeupdown(CAMERA_DOWN);
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

void trafficmenu(GLint option) {
}

void addcarmenu(GLint option) {
	myWorld.traffic->MenuAddCar(option);
}
void deletecarmenu(GLint option) {
	myWorld.traffic->MenuDeleteCar(option);
}

void timemenu(GLint option) {
	if (option == MENU_TIME_MORNING) {
		GlobalTime = 7;
		SkyColor->set(0.67, 0.93, 0.93, 1);
		myWorld.settime(MENU_TIME_MORNING);

	} else if (option == MENU_TIME_NIGHT) {
		GlobalTime = 19;
		SkyColor->set(0, 0, 0, 1);
		myWorld.settime( MENU_TIME_NIGHT);
	} else if (option == MENU_TIME_RESUME) {
		glutIdleFunc(idleFunc);
	} else if (option == MENU_TIME_PAUSE) {
		glutIdleFunc(NULL);
	}

}
void menu() {
	GLint timeMenu = glutCreateMenu(timemenu);
	glutAddMenuEntry(" Morning", 0);
	glutAddMenuEntry(" Night", 1);

	GLint deleteCarMenu = glutCreateMenu(deletecarmenu);
	glutAddMenuEntry(" East", 0);
	glutAddMenuEntry(" West", 1);
	glutAddMenuEntry(" North", 2);
	glutAddMenuEntry(" South", 3);

	GLint addCarMenu = glutCreateMenu(addcarmenu);
	glutAddMenuEntry(" East", 0);
	glutAddMenuEntry(" West", 1);
	glutAddMenuEntry(" North", 2);
	glutAddMenuEntry(" South", 3);

	GLint TrafficMenu = glutCreateMenu(trafficmenu);
	glutAddSubMenu(" Add Car", addCarMenu);
	glutAddSubMenu(" Delete Car", deleteCarMenu);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" Time", timeMenu);
	glutAddSubMenu(" Traffic Control", TrafficMenu);
	glutAddMenuEntry(" Quit", 2);
}

int main(int argc, char** argv) {
	PlaySound((LPCSTR) "Background.wav", NULL,
	SND_FILENAME | SND_ASYNC | SND_LOOP);
	setvbuf(stdout, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	centerwindow(glutGet(GLUT_SCREEN_HEIGHT), glutGet(GLUT_SCREEN_WIDTH));
	glutInitWindowPosition(winx, winy);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow(WIN_TITLE);
	init();
	menu();
	setTexture();
	glutDisplayFunc(display);
	glutMouseFunc(mouseAction);
	glutKeyboardFunc(keyboardFunc);
	glutIdleFunc(idleFunc);
	glutPassiveMotionFunc(passivemouseFunc);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
