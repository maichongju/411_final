/*
 * Tree.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author:Benjamin Ngan
 */
#include "Tree.hpp"
#include <iostream>
#include <stdio.h>
tree::tree() {
	cone = new Cone();
	cylinder = new Cylinder();
	cube = new Cube();

	sphere = new Sphere(new Point(0.05, 0.04, 0.2), new Color(.60, .30, 0, 0),
			0.04);
	position = new Point(0, 0, 0);
}
tree::tree(float x, float y, float z) {
	cone = new Cone();
	cylinder = new Cylinder();
	cube = new Cube();
	cube->translate(x, y, z + .4);
	cube->scale(.5, .5, .5);
	sphere = new Sphere(new Point(0.00, 0.00, 0.0), new Color(.30, .80, 0, 0),
			0.2);
	sphere->translate(x, y, z + .4);
	position = new Point(x, y, z);
}
void tree::draw(float x, float y, float z, int treetype) {
	cylinder->draw(x, y, z);
	switch (treetype) {
	case (0): {
		cone->draw(x, y, z + .4);
		break;
	}
	case (1): {
		cube->draw();
		for (int i = 0; i <= 6; i++) {
			cube->changeFaceColor(i, .30, .80, 0);
		}
		break;
	}
	case (2): {
		sphere->draw();
		//sphere->translate(x, y, z + .4);
		break;
	}
	}




}

/*
TopofTree::TopofTree() {
	cone = new Cone();
}

void TopofTree::draw(float x, float y, float z) {
	cone->draw(x, y, z);
}

Trunk::Trunk() {
	cylinder = new Cylinder();
}
void Trunk::draw(float x, float y, float z) {
	cylinder->draw(x, y, z);
}

 */


