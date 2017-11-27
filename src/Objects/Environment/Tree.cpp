/*
 * Tree.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author:Benjamin Ngan
 */
#include "Tree.hpp"
#include <iostream>
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
	sphere = new Sphere(new Point(0.05, 0.04, 0.2), new Color(.60, .30, 0, 0),
			0.04);
	position = new Point(0, 0, 0);
}
void tree::draw(float x, float y, float z, int treetype) {
	cylinder->draw(x, y, z);
	switch (treetype) {
	case (0): {
		cone->draw(x, y, z);
		break;
	}
	case (1): {
		cube->translate(x, y, z);
		cube->draw();

		break;
	}
	case (2): {
		sphere->draw();
		sphere->translate(x, y, z);
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


