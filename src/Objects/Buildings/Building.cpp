#include "Building.hpp"
// Class Window

Window::Window() {
	position = new Point(0, 0, 0);
	Light = false;
	direction = BUILDING_WINDOW_FRONT;
}

Window::Window(Point *position, int direction) {
	this->position = new Point(position->x, position->y, position->z);
	Light = false;
	this->direction = direction;
}
void Window::draw(Point *p) {
	if (Light) {
		glColor3f(1, 1, 0);
	} else {
		glColor3f(0, 0, 0);
	}
	float x = position->x + p->x;
	float y = position->y + p->y;
	float z = position->z + p->z;
	glBegin(GL_POLYGON);

	switch (direction) {
	case BUILDING_WINDOW_FRONT: {
		glVertex3f(x, y, z + 0.0001);
		glVertex3f(x + 0.1, y, z + 0.0001);
		glVertex3f(x + 0.1, y + 0.2, z + 0.0001);
		glVertex3f(x, y + 0.2, z + 0.0001);
		break;
	}
	case BUILDING_WINDOW_REAR: {

		glVertex3f(x, y, z - 0.0001);
		glVertex3f(x, y + 0.2, z - 0.0001);
		glVertex3f(x + 0.1, y + 0.2, z - 0.0001);
		glVertex3f(x + 0.1, y, z - 0.0001);
		break;
	}
	case BUILDING_WINDOW_LEFT: {
		glVertex3f(x - 0.0001, y, z);
		glVertex3f(x - 0.0001, y + 0.2, z);
		glVertex3f(x - 0.0001, y + 0.2, z - 0.1);
		glVertex3f(x - 0.0001, y, z - 0.1);
		break;

	}
	case BUILDING_WINDOW_RIGHT: {
		glVertex3f(x + 0.0001, y, z);
		glVertex3f(x + 0.0001, y, z - 0.1);
		glVertex3f(x + 0.0001, y + 0.2, z - 0.1);
		glVertex3f(x + 0.0001, y + 0.2, z);
		break;
	}
	}
	glEnd();
}

void Window::setLight(bool status) {
	this->Light = status;
}
// **************************************************************
// Class Building
/**
 * Constructor
 */
Building::Building() {
	cube = new Cube();
	position = new Point(0, 0, 0);
	outColor = new Color(1, 1, 1, 1);
	topColor = new Color(0, 0, 0, 1);
	x = y = z = 1;
	//setBuildingColor();
	setBuildingShape();
	windows = 0;
	setBuildingWindows(1, 1, 1, 1);


}
/**
 * Constructor
 * @param x
 * @param y
 * @param z
 */
Building::Building(float x, float y, float z) {
	cube = new Cube();
	cube->translate(x, y, z);
	position = new Point(x, y, z);
	outColor = new Color(220 / 256, 220 / 256, 220 / 256, 1);
	topColor = new Color(1, 1, 1, 1);
	x = y = z = 1;
	//setBuildingColor();
	setBuildingShape();
	windows = 0;

}

/**
 * Constructor
 * @param x
 * 			x need to place in the map
 * @param y
 * 			y need to place in the map
 * @param z
 * 			z need to place in the map
 * @param outcolor
 * 			color for building side color
 * @param topcolor
 * 			color for building top color
 */
Building::Building(float x, float y, float z, Color outcolor, Color topcolor) {
	cube = new Cube();
	cube->translate(x, y, z);
	position = new Point(x, y, z);
	outColor = new Color(outcolor.red, outcolor.green, outcolor.blue,
			outcolor.alpha);
	topColor = new Color(topcolor.red, topcolor.green, topcolor.blue,
			topcolor.alpha);
	x = y = z = 1;
	setBuildingColor();
	setBuildingShape();
	windows = 0;
	setBuildingWindows(1, 0, 0, 0);

}
/**
 * Function for drawing the building
 */
void Building::draw() {
	cube->draw();
	int i;
	for (i = 0; i < windows; i++) {
		window[i]->draw(this->position);
	}
}

/**
 * Function will set the building color each time change the color
 */
void Building::setBuildingColor() {
	int i;
	// Set the color for side color
	for (i = 0; i < 4; i++) {
		cube->changeFaceColor(i, outColor->red, outColor->green,
				outColor->blue);
	}

	// Set the color for top color
	cube->changeFaceColor(4, topColor->red, topColor->green, topColor->blue);

	cube->changeFaceColor(5, 0, 0, 0);

}
/**
 * Function will set the building shape
 */
void Building::setBuildingShape() {
	float x = 0.5, y = 1, z = 0.25;
	cube->scale(x, y, z);
	this->x *= x;
	this->y *= y;
	this->z *= z;
}
/**
 * Function will scale the building
 * @param x
 * 			x need to scale for
 * @param y
 * 			y need to scale for
 * @param z
 * 			z need to scale for
 */
void Building::scale(float x, float y, float z) {
	cube->scale(x, y, z);
	this->x *= x;
	this->y *= y;
	this->z *= z;
}
/**
 * Function will generate the number of windows
 * @param front
 * @param right
 * @param rear
 * @param left
 */
void Building::setBuildingWindows(int front, int right, int rear, int left) {
	window[0] = new Window(
			new Point(x / 5, y / 3, z), BUILDING_WINDOW_FRONT);
	window[3] = new Window(new Point(x, y / 3, z / 2),
	BUILDING_WINDOW_RIGHT);
	window[1] = new Window(new Point(x / 5, y / 3, 0), BUILDING_WINDOW_REAR);
	window[2] = new Window(new Point(0, y / 3, z / 2), BUILDING_WINDOW_LEFT);
	windows = 4;


}
