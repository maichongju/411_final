/*
 * Tree.hpp
 *
 *  Created on: Nov 25, 2017
 *      Author: Benjamin Ngan
 */

#ifndef SRC_OBJECTS_ENVIRONMENT_TREE_HPP_
#define SRC_OBJECTS_ENVIRONMENT_TREE_HPP_

#include "../Basic/Cone.hpp"
#include "../Basic/Cylinder.hpp"
#include "../Basic/Cube.hpp"
#include "../Basic/Sphere.hpp"
#include "../Basic/Shape.hpp"
#include "../Basic/Point.hpp"
#include "../../Color.hpp"
#include "../../Texture/RGBpixmap.h"
#include "../../Constant.hpp"
#include <stdio.h>
extern RGBpixmap texture[];

class Tree {
public:
	Tree();
	Tree(float x, float y, float z, int tt);
	Tree(float x, float y, float z, float a, float b, float c, int tt);
	void draw();
private:
	Cone *cone;
	Cylinder *cylinder;
	Cube *cube;
	Sphere *sphere;
	Point *position;
	int treeType;


};
/*
class TopofTree {
public:
	TopofTree();
	void draw(float x, float y, float z);
private:
	Cone *cone;
};

class Trunk {
public:
	Trunk();
	void draw(float x, float y, float z);
	//void translate(float x, float y, float z);
private:
	Cylinder *cylinder;

};
 */


#endif /* SRC_OBJECTS_ENVIRONMENT_TREE_HPP_ */
