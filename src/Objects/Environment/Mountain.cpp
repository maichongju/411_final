#include "Mountain.hpp"
Mountain::Mountain() {
	TextureID = -1;
	p = new Pyramid();
}

Mountain::Mountain(float x, float y, float z) {
	TextureID = -1;
	p = new Pyramid();
	this->p->translate(x, y, z);
}

void Mountain::translate(float x, float y, float z) {
	this->p->translate(x, y, z);
}

void Mountain::draw() {
	if (TextureID != -1) {
		this->p->drawtexture(this->TextureID);
	} else {
		this->p->draw();
	}
}

void Mountain::scale(float s){
	this->p->scale_change(s);
}

void Mountain::setTextureID(int Texture){
	this->TextureID = Texture;

}

