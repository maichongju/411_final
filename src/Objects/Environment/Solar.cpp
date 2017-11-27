#include "Solar.hpp"

Solar::Solar() {
	sun = new Sphere(new Point( SUN_DIS, 0, 0), TEXTURE_SUN, SUN_SIZE);
	moon = new Sphere(new Point(-MOON_DIS, 0, 0), TEXTURE_MOON, MOON_SIZE);
}

Solar::~Solar() {
	delete sun;
	delete moon;

}

void Solar::settime(int time) {
	this->~Solar();
	if (time == MENU_TIME_MORNING) {
		sun = new Sphere(new Point( SUN_DIS, 0, 0), TEXTURE_SUN, SUN_SIZE);
		moon = new Sphere(new Point(-MOON_DIS, 0, 0), TEXTURE_MOON, MOON_SIZE);
	} else if (time == MENU_TIME_NIGHT) {
		sun = new Sphere(new Point(- SUN_DIS, 0, 0), TEXTURE_SUN, SUN_SIZE);
		moon = new Sphere(new Point(MOON_DIS, 0, 0), TEXTURE_MOON, MOON_SIZE);
	}
}

void Solar::draw() {
	sun->rotate_origin(0, 0, 1, -SOLAR_ROTATE);
	sun->rotate_mc(1, 1, 1, 0.01);
	sun->drawtexture();
	moon->rotate_origin(0, 0, 1, -SOLAR_ROTATE);
	moon->rotate_mc(1, 1, 1, 0.01);
	moon->drawtexture();
}

