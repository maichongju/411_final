#include "Color.hpp"


Color::Color() {
	red = green = blue = alpha = 0;
}

Color::Color(float red, float green, float blue, float alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}


void Color::set(float red, float green, float blue, float alpha) {
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

void Color::scale(float s) {
	this->red *= s;
	this->green *= s;
	this->blue *= s;
}

void Color::SkyfadeOut() {
	this->red -= 0.01;
	this->green -= 0.01;
	this->blue -= 0.01;
	if (this->red <= 0) {
		this->red = 0;
	}
	if (this->green <= 0) {
		this->green = 0;
	}
	if (this->blue <= 0) {
		this->blue = 0;
	}
}

void Color::SkyfadeIn() {
	this->red += 0.01;
	this->green += 0.01;
	this->blue += 0.01;
	if (this->red > 0.63) {
		this->red = 0.63;
	}
	if (this->green > 0.93) {
		this->green = 0.93;
	}
	if (this->blue > 0.93) {
		this->blue = 0.93;
	}
}
