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
/**
 * Function will draw the given window
 * @param p
 * 			position for the building
 */

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

/**
 * Function will set the light status
 * @param status
 */
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
	outColor = new Color(0.5, 0.5, 0.5, 1);
	topColor = new Color(1, 1, 1, 1);
	this->x = this->y = this->z = 1;
	setBuildingColor();
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
	outColor = new Color(0.5, 0.5, 0.5, 1);
	topColor = new Color(1, 1, 1, 1);
	this->x = this->y = this->z = 1;
	setBuildingColor();
	setBuildingShape();
	windows = 0;
	//setBuildingWindows(1, 1, 1, 1);

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
	this->x = this->y = this->z = 1;
	setBuildingColor();
	setBuildingShape();
	windows = 0;
	//setBuildingWindows(1, 0, 0, 0);

}
/**
 * Function for drawing the building
 */
void Building::draw() {
	cube->draw();
	int i;
	for (i = 0; i < windows; i++) {
		if (GlobalTime > 19 && GlobalTime < 20) {
			window[i]->setLight(true);
		} else if (GlobalTime > 7 && GlobalTime < 8) {
			window[i]->setLight(false);
		}
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
 * 				number of windows are showing at the front
 * @param right
 * 				number of windows are showing at the right
 * @param rear
 * 				number of windows are showing at the rear
 * @param left
 * 				number of windows are showing at the left
 */
void Building::setBuildingWindows(int front, int right, int rear, int left) {
	windows = front + right + rear + left;
	int index = 0;

	// Calculate front/rear windows
	float x = 0.05, y = 0.35, z = this->z;
	float i;

	for (i = 0; i < front; i++) {
		window[index] = new Window(new Point(x, y, z), BUILDING_WINDOW_FRONT);
		x += 0.15;
		if (x > this->x - 0.05) {
			y += 0.35;
			x = 0.05;
		}
		index++;
	}
	x = 0.05, y = 0.35;
	for (i = 0; i < rear; i++) {
		window[index] = new Window(new Point(x, y, 0), BUILDING_WINDOW_REAR);
		x += 0.15;
		if (x > this->x - 0.05) {
			y += 0.35;
			x = 0.05;
		}
		index++;
	}
	z = this->z - 0.075, y = 0.35;
	for (i = 0; i < left; i++) {
		window[index] = new Window(new Point(0, y, z), BUILDING_WINDOW_LEFT);
		z -= 0.15;
		if (z < 0.05) {
			y += 0.35;
			z = this->z - 0.075;
		}
		index++;
	}
	z = this->z - 0.075, y = 0.35, x = this->x;
	for (i = 0; i < right; i++) {
		window[index] = new Window(new Point(x, y, z), BUILDING_WINDOW_RIGHT);
		z -= 0.15;
		if (z < 0.05) {
			y += 0.35;
			z = this->z - 0.075;
		}
		index++;
	}


}
