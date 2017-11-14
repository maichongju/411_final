#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Cube.hpp"
#include "Mesh.hpp"
#include <iostream>
#include <list>
#include <vector>


class World {
public:
	Shape* list[2];
	World();
	~World();
	void draw_world(); // draw all objects in the world
	void reset(); // Will reset the world to the basic

private:
	void draw();
};

#endif
