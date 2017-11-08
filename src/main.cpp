#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "World.hpp"
#include "Constant.hpp"
#include "Color.hpp"

char NEWGAMETEXT[] = "Press \"S\" to start";
char SCORETEXT[] = "Score: ";
char GAMEOVERTEXT[] = "GAME OVER";
char GAMEOVERSCORETEXT[] = "Your Score is ";
char GAMEPAUSETEXT[] = "Pause";
char GAMERESUMEHINTTEXT[] = "Press 'Esc' to resume";
char GAMERESTARTTEXT[] = "Press \"R\" to restart";
char GAMEHIGHSCORETEXT[] = "HighScore: ";

Color SCORETEXTCOLOR(1, 1, 1, 1);
Color SCORECOLOR(1, 0, 0, 1);
Color TEXTCOLOR(1, 1, 1, 1); //General text color (New game text and end game text)

GLint winWidth = WIN_WIDTH, winHeight = WIN_HEIGHT, winx = 100, winy = 100;

int GameStatus = GAME_STATUS_NEW;
int GameLevel = GAME_LEVEL_NORMAL;
int KeyDirection = GAME_KEY_RIGHT, KeyDirectionPause = GAME_KEY_NULL;
int GameType = GAME_TYPE_NORMAL;
int Score = 0; // Maximum is 99999
int HighScore = 0;
double snakemove;

World myWorld;

/**
 * Function will reset everything for a new game
 */
void NewGame(void) {
	GameStatus = GAME_STATUS_NEW;
	myWorld.reset();
	Score = 0;

}
/**
 * Function for idle
 */
static int oldTime, newTime;
void move() {
	oldTime = clock();
	snakemove = (newTime - oldTime);
	newTime = clock();
	oldTime = newTime;
	glutPostRedisplay();
}

/**
 * Function will call by display. Display needed text to the screen
 */
void setText(void) {
	int i, size;
	char scorechar[6];
	if (GameStatus != GAME_STATUS_END) {
		glRasterPos2f(2, 97);
		glColor4f(SCORETEXTCOLOR.red, SCORETEXTCOLOR.green, SCORETEXTCOLOR.blue,
				SCORETEXTCOLOR.alpha);
		for (i = 0; SCORETEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, SCORETEXT[i]);
		}

		sprintf(scorechar, "%05d", Score);
		//glColor4f(SCORECOLOR.red, SCORECOLOR.green, SCORECOLOR.blue,
		//	SCORECOLOR.alpha);
		for (i = 0; scorechar[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorechar[i]);
		}
	}

	if (GameStatus == GAME_STATUS_NEW) {
		size = length(NEWGAMETEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size / 2, GAME_ZONE_HEIGHT / 2);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; NEWGAMETEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, NEWGAMETEXT[i]);
		}

	} else if (GameStatus == GAME_STATUS_END) {
		size = length(GAMEOVERTEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size * 0.75,
		GAME_ZONE_HEIGHT / 2 + 4);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; GAMEOVERTEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, GAMEOVERTEXT[i]);
		}
		size = length(GAMEOVERSCORETEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size / 2, GAME_ZONE_HEIGHT / 2);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; GAMEOVERSCORETEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,
					GAMEOVERSCORETEXT[i]);
		}
		sprintf(scorechar, "%d", Score);
		for (i = 0; scorechar[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorechar[i]);
		}
		size = length(GAMERESTARTTEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size / 2, GAME_ZONE_HEIGHT / 2 - 4);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; GAMERESTARTTEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, GAMERESTARTTEXT[i]);
		}
	} else if (GameStatus == GAME_STATUS_PAUSE) {
		size = length(GAMEPAUSETEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size / 2, GAME_ZONE_HEIGHT / 2 + 4);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; GAMEPAUSETEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, GAMEPAUSETEXT[i]);
		}
		size = length(GAMERESUMEHINTTEXT);
		glRasterPos2f(GAME_ZONE_WIDTH / 2 - size / 2, GAME_ZONE_HEIGHT / 2);
		glColor4f(TEXTCOLOR.red, TEXTCOLOR.green, TEXTCOLOR.blue,
				TEXTCOLOR.alpha);
		for (i = 0; GAMERESUMEHINTTEXT[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,
					GAMERESUMEHINTTEXT[i]);
		}
	}

	glRasterPos2f(75, 97);
	glColor4f(SCORETEXTCOLOR.red, SCORETEXTCOLOR.green, SCORETEXTCOLOR.blue,
			SCORETEXTCOLOR.alpha);
	for (i = 0; GAMEHIGHSCORETEXT[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, GAMEHIGHSCORETEXT[i]);
	}

	sprintf(scorechar, "%05d", HighScore);
	for (i = 0; scorechar[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorechar[i]);
	}

}
/**
 * Function will called by glutKeyboardFunc, react for key input (ASCII key)
 * @param key
 * 			the key that the user pressed
 * @param x
 * 			position x of mouse while the key press
 * @param y
 * 			position y of mouse while the key press
 */
void keyboardFunc(unsigned char key, int x, int y) {
	if (GameStatus == GAME_STATUS_NEW) {
		if (key == 's' || key == 'S') {
			GameStatus = GAME_STATUS_RUNNING;
			KeyDirection = GAME_KEY_RIGHT;
			glutIdleFunc(move);
		}
	} else if (GameStatus == GAME_STATUS_RUNNING) {
		if (key == 27) { // 27 is Esc (ASCII)
			GameStatus = GAME_STATUS_PAUSE;
			KeyDirectionPause = KeyDirection;
			KeyDirection = GAME_KEY_NULL;
			glutIdleFunc(NULL);
			snakemove = 0;
		}
	} else if (GameStatus == GAME_STATUS_PAUSE) {
		if (key == 27) {
			GameStatus = GAME_STATUS_RUNNING;
			KeyDirection = KeyDirectionPause;
			KeyDirectionPause = GAME_KEY_NULL;
			glutIdleFunc(move);
		}
	} else if (GameStatus == GAME_STATUS_END) {
		if (key == 'r' || 'R') {
			GameStatus = GAME_STATUS_NEW;
			NewGame();
		}
	}

}
/**
 * Function will called by glutSpecialFunc, react for special key input (Non-ASCII)
 * @param key
 * 			the key that the user pressed
 * @param x
 * 			position x of mouse while the key press
 * @param y
 * 			position y of mouse while the key press
 */
void specialFunc(int key, int x, int y) {
	if (GameStatus == GAME_STATUS_RUNNING) {
		if (key == GLUT_KEY_UP) {
			if (KeyDirection != GAME_KEY_DOWN) {
				KeyDirection = GAME_KEY_UP;
			}
		} else if (key == GLUT_KEY_DOWN) {
			if (KeyDirection != GAME_KEY_UP) {
				KeyDirection = GAME_KEY_DOWN;
			}
		} else if (key == GLUT_KEY_LEFT) {
			if (KeyDirection != GAME_KEY_RIGHT) {
				KeyDirection = GAME_KEY_LEFT;
			}
		} else if (key == GLUT_KEY_RIGHT) {
			if (KeyDirection != GAME_KEY_LEFT) {
				KeyDirection = GAME_KEY_RIGHT;
			}
		}
	}

}
/**
 * Function will draw the border of the current game size. Default color is white
 */
void drawBorder(void) {
	glLineWidth(1.5);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(0, 96);
	glVertex2i(100, 96);
	glEnd();
}

/**
 * Function will set the window title with current level
 */
void changeTitle(void) {
	char str[50];
	strcpy(str, WIN_TITLE);
	if (GameLevel == GAME_LEVEL_EASY) {

		strcat(str, "   EASY");
	} else if (GameLevel == GAME_LEVEL_NORMAL) {
		strcat(str, "   NORMAL");
	} else if (GameLevel == GAME_LEVEL_HARD) {
		strcat(str, "   HARD");
	} else if (GameLevel == GAME_LEVEL_EXPERT) {
		strcat(str, "   EXPERT");
	} else if (GameLevel == GAME_LEVEL_EEXPERT) {
		strcat(str, "   EEXPERT");
	}
	glutSetWindowTitle(str);

}

/**
 * Function will update the high score
 */
void updateHighScore() {
	if (GameStatus == GAME_STATUS_END) {
		if (Score > HighScore) {
			HighScore = Score;
		}
	}
}
/**
 * Function is set for display, every time the screen refresh will run this function
 */
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	changeTitle();
	updateHighScore();
	setText();
	drawBorder();
	myWorld.draw();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
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
	case 5: {
		GameLevel = GAME_LEVEL_EEXPERT;
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
		myWorld.snake->setColor(1.0, 0, 0, 1);
		break;
	}
	case 2: {
		myWorld.snake->setColor(0, 1.0, 0, 1.0);
		break;

	}

	case 3: {
		myWorld.snake->setColor(0, 0, 1.0, 1.0);
		break;
	}
	case 4: {
		myWorld.snake->setColor(1.0, 1.0, 1.0, 1.0);
	}
	}

}

void blockMenu(GLint boption) {
	switch (boption) {
	case 1: {
		myWorld.block->setColor(1.0, 0, 0, 1.0);

		break;
	}
	case 2: {
		myWorld.block->setColor(0, 1.0, 0, 1.0);

		break;
	}
	case 3: {
		myWorld.block->setColor(0, 0, 1.0, 1.0);

		break;
	}
	case 4: {
		myWorld.block->setColor(1.0, 1.0, 1.0, 1.0);
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
		if (GameStatus == GAME_STATUS_RUNNING) {
			GameStatus = GAME_STATUS_PAUSE;
		}
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
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	glutAddMenuEntry(" White", 4);

	int levelmenu = glutCreateMenu(levelMenu);
	glutAddMenuEntry(" Easy", 1);
	glutAddMenuEntry(" Normal", 2);
	glutAddMenuEntry(" Hard", 3);
	glutAddMenuEntry(" Expert", 4);
	glutAddMenuEntry(" YOU DON'T WANT THIS", 5);

	int bcolormenu = glutCreateMenu(blockMenu);
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	glutAddMenuEntry(" White", 4);

	glutCreateMenu(mainMenu);
	glutAddMenuEntry(" New Game", 1);
	glutAddMenuEntry(" Pause", 2);
	glutAddSubMenu(" Snake Color", colormenu);
	glutAddSubMenu(" Block Color", bcolormenu);
	glutAddSubMenu(" Level", levelmenu);
	glutAddMenuEntry(" Exit Game", 3);
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	centerwindow(glutGet(GLUT_SCREEN_HEIGHT), glutGet(GLUT_SCREEN_WIDTH));
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow(WIN_TITLE);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, GAME_SIZE_WIDTH, 0.0, GAME_SIZE_HEIGHT);
	glColor3f(1.0, 1.0, 1.0);

	glutDisplayFunc(display);
	glutSpecialFunc(specialFunc);
	glutKeyboardFunc(keyboardFunc);

	menu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
