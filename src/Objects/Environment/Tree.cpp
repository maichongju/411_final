/*
 * Tree.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author:Benjamin Ngan
 */
#include "Tree.hpp"

tree::tree() {
	treeType = 0;
	cone = new Cone();
	cylinder = new Cylinder();
	cube = new Cube();

	sphere = new Sphere(new Point(0, 6, 0), TEXTURE_LEAF, 0.25);
	position = new Point(0, 0, 0);

}
tree::tree(float x, float y, float z, int tt) {
	treeType = tt;
	cone = new Cone(x, z * -1, y + .4);
	cylinder = new Cylinder(x, z * -1, y, TEXTURE_TREE_BARK);
	cube = new Cube();
	cube->translate(x - .15, y + .4, z - .15);
	cube->scale(.3, .3, .3);
	sphere = new Sphere(new Point(0, 0, 0), TEXTURE_LEAF, 0.25);
	//sphere->translate(x, y - .5, z - 25);
	sphere->translate(x, y + .4, z);
	position = new Point(x, y, z);
}
void tree::draw() {
	int treetype = this->treeType;
	cylinder->drawtexture();
	switch (treetype) {
	case (0): {
		cone->draw();
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
		sphere->drawtexture();
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


