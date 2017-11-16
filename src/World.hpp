#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Objects/Traffic/Traffic.hpp"
#include "Objects/Buildings/Buildings.hpp"

#include "Constant.hpp"

#include <iostream>
#include <list>
#include <vector>

class World {
public:
	World();
	~World();
	void draw_world(); // draw all objects in the world
	void reset(); // Will reset the world to the basic

private:
	Traffic *cube;
	Buildings *b;
	void draw();
};

#endif
