#include "Color.hpp"

Color::Color() {
	red = green = blue = alpha = 0;
}

void Color::set(float red, float green, float blue, float alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}
