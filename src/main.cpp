#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "World.hpp"
#include "Constant.hpp"

char NEWGAMETEXT[] = "Press \"S\" to start";

GLint winWidth = 800, winHeight = 800, winx = 100, winy = 100;

int GameStatus = GAME_STATUS_NEW, GameLevel = GAME_LEVEL_NORMAL;
int SnakeSpeed = 5;

/**
 * Function will call by display. Display the New text and End game text on the screen
 */
void setText(void) {
	glPushMatrix();

	glRasterPos2f(-0.25, 0);
	if (GameStatus == GAME_STATUS_NEW) {
		int i;
		for (i = 0; NEWGAMETEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, NEWGAMETEXT[i]);
		}
	}
	glPopMatrix();

}

/**
 * Function is set for display, every time the screen refresh will run this function
 */
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setText();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

/**
 * Every time window reshape it will call this function
 * @param newWidth
 * 			the new width for the window
 * @param newHeight
 * 			the new height for the window
 */
void winReshapeFun(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newWidth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

/**
 * Function will attach to glutMouseFunc, it will receive the info from system
 * @param button
 * 			the button clicked
 * @param state
 * 			the state of the button
 * @param x
 * 			the x position of the mouse clicked
 * @param y
 * 			the y position of the mouse clicked
 */
void mouseAction(int button, int state, int x, int y) {

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
		winx = screen_width / 2 - winWidth / 2;
		winy = screen_height / 2 - winHeight / 2;
	}
}
/**
 * Function will reset everything for a new game
 */
void NewGame(void) {
	GameStatus = GAME_STATUS_NEW;

}
/**
 * Level Menu
 * @param leveloption
 * 			user selected item id
 */
void levelMenu(GLint leveloption) {
	switch (leveloption) {
	case 1: {
		GameLevel = GAME_LEVEL_EASY;
		break;
	}
	case 2: {
		GameLevel = GAME_LEVEL_NORMAL;
		break;
	}
	case 3: {
		GameLevel = GAME_LEVEL_HARD;
		break;
	}
	case 4: {
		GameLevel = GAME_LEVEL_EXPERT;
		break;
	}
	}

}
/**
 * Color Menu for snake
 * @param colorOption
 * 			user selected item id
 */
void colorMenu(GLint colorOption) {
	switch (colorOption) {
	case 1: {

		break;
	}
	case 2: {

		break;

	}

	case 3: {

		break;
	}
	}

}

/**
 * Set up the function for top menu
 * @param option
 * 			user selected item id
 */
void mainMenu(GLint option) {
	switch (option) {
	case 1: {
		NewGame();
		break;
	}
	case 2: {
		GameStatus = GAME_STATUS_PAUSE;
		break;
	}
	case 3: {
		exit(0);
	}
	}
}

/**
 * Function will set up top-level menu
 */
void menu() {
	int colormenu = glutCreateMenu(colorMenu);
	glutAddMenuEntry(" Color 1", 1);
	glutAddMenuEntry(" Color 2", 2);
	glutAddMenuEntry(" Color 3", 3);

	int levelmenu = glutCreateMenu(levelMenu);
	glutAddMenuEntry(" Easy", 1);
	glutAddMenuEntry(" Normal", 2);
	glutAddMenuEntry(" Hard", 3);
	glutAddMenuEntry(" Expert", 4);

	glutCreateMenu(mainMenu);
	glutAddMenuEntry(" New Game", 1);
	glutAddMenuEntry(" Pause", 2);
	glutAddSubMenu(" Snake Color", colormenu);
	glutAddSubMenu(" Level", levelmenu);
	glutAddMenuEntry(" Exit Game", 3);
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	centerwindow(glutGet(GLUT_SCREEN_HEIGHT), glutGet(GLUT_SCREEN_WIDTH));
	glutInitWindowPosition(winx, winy);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CP411 Final Project (Please do not resize the window)");
	glutDisplayFunc(display);
	glutMouseFunc(mouseAction);
	glutReshapeFunc(winReshapeFun);
	menu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
