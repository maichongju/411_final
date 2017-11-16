#include "TrafficLight.hpp"
//Light Class
Light::Light(Point *p, Color *lightcolor) {
	this->lightcolor = new Color(lightcolor->red, lightcolor->green,
			lightcolor->blue, lightcolor->alpha);
	this->position = new Point(p->x, p->y, p->z);
	On = false;
}

void Light::draw(Point *p) {

}

/**
 * Function will set on or off for the light
 * @param on
 * 			on true, off false
 */
void Light::setOn(bool on) {
	On = on;
}

//******************************************
// Traffic Light Class
TrafficLight::TrafficLight(Point *p) {
	this->position = new Point(p->x, p->y, p->z);
}
void TrafficLight::draw() {

}
