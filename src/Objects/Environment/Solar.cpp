#include "Solar.hpp"

Solar::Solar(){
	sun = new Sphere(new Point(0,7,0),TEXTURE_SUN,0.25);
	moon = new Sphere(new Point(0,1,0),TEXTURE_MOON,0.15);
}

void Solar::draw(){
	sun->drawtexture();
	moon->drawtexture();
}
