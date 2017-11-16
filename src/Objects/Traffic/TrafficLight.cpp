#include "TrafficLight.hpp"
//Light Class
Light::Light(Point *p, Color *lightcolor) {
	this->lightcolor = new Color(lightcolor->red, lightcolor->green,
			lightcolor->blue, lightcolor->alpha);
	this->offlightcolor = (new Color(lightcolor->red, lightcolor->green,
			lightcolor->blue, lightcolor->alpha));
	offlightcolor->scale(0.25);
	this->position = new Point(p->x, p->y, p->z);
	On = false;
	s = new Sphere(position, lightcolor, 0.03);
}

void Light::draw(Point *p) {
	if (On) {
		s->draw(lightcolor, p);
	} else {
		s->draw(offlightcolor, p);
	}

}
void Light::translate(float x, float y, float z) {
	s->translate(x, y, z);
}
void Light::rotate(float x, float y, float z, float angle) {
	s->rotate(x, y, z, angle);
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
TrafficLight::TrafficLight(Point *p, int L) {
	this->position = new Point(p->x, p->y, p->z);
	Facing = L;
	Body = new Cube();
	Body->translate(p->x, p->y + 0.35, p->z);
	Body->scale(0.25, 0.08, 0.08);
	Body->rotate_mc(0, 1, 0, Facing);
	pass = false;
	setBodyColor();
	setLight();

}
void TrafficLight::draw() {
	Body->draw();

	int i;
	for (i = 0; i < 3; i++) {
		LightFront[i]->draw(this->position);
		LightRear[i]->draw(this->position);
	}
}

void TrafficLight::setBodyColor() {
	int i;
	for (i = 0; i < 6; i++) {
		Body->changeFaceColor(i, 1, 0.75, 0);
	}
}

void TrafficLight::setLight() {
	LightFront[0] = new Light(new Point(0.05, 0.39, 0.08),
			new Color(1, 0, 0, 1)); //Red
	LightFront[1] = new Light(new Point(0.12, 0.39, 0.08),
			new Color(1, 1, 0, 1)); //Yellow
	LightFront[2] = new Light(new Point(0.19, 0.39, 0.08),
			new Color(0, 1, 0, 1)); //Green
	LightRear[0] = new Light(new Point(0.05, 0.39, 0.00),
			new Color(1, 0, 0, 1));
	LightRear[1] = new Light(new Point(0.12, 0.39, 0.00),
			new Color(1, 1, 0, 1)); //Yellow
	LightRear[2] = new Light(new Point(0.19, 0.39, 0.00),
			new Color(0, 1, 0, 1)); //Green
	int i;
	for (i = 0; i < 3; i++) {
		LightFront[i]->rotate(0, 1, 0, Facing);
		LightFront[i]->translate(position->x, position->y, position->z);
		LightRear[i]->rotate(0, 1, 0, Facing);
		LightRear[i]->translate(position->x, position->y, position->z);
	}
}

void TrafficLight::setLight(int light) {
	if (LightUp != TRAFFIC_LIGHT_OFF) {
		LightFront[LightUp]->setOn(false);
		LightRear[LightUp]->setOn(false);
	}
	LightFront[light]->setOn(true);
	LightRear[light]->setOn(true);
	if (light == TRAFFIC_LIGHT_GREEN) {
		pass = true;
	} else {
		pass = false;
	}
	LightUp = light;
}
