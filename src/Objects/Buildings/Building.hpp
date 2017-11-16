
#ifndef SRC_OBJECTS_BUILDINGS_BUILDING_HPP_
#define SRC_OBJECTS_BUILDINGS_BUILDING_HPP_

#include "../Basic/Cube.hpp"
#include "../../Color.hpp"
#include "../Basic/Point.hpp"

#include "../../Constant.hpp"
#include <stdio.h>

class Window {
public:
	Window();
	Window(Point *position, int direction);
	void draw(Point *position);
	void setLight(bool status);
private:
	int direction;
	bool Light; //Default light is off
	Point *position;
};

class Building {
public:
	Building();
	Building(float x, float y, float z);
	Building(float x, float y, float z, Color outcolor, Color topcolor);
	void scale(float x, float y, float z);
	void draw();
	void setBuildingWindows(int front, int right, int rear, int left);
private:
	int windows;
	Point *position;
	float x, y, z;
	Color *outColor, *topColor;
	Cube *cube;
	Window *window[20];
	void setBuildingColor();
	void setBuildingShape();
};

#endif /* SRC_OBJECTS_BUILDINGS_BUILDING_HPP_ */
