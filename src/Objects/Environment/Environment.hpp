#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>
#include "Ground.hpp"
#include "Solar.hpp"
#include "../Basic/Cylinder.hpp"
#include "../Basic/Cone.hpp"
#include "../Basic/Pyramid.hpp"

#include "Tree.hpp"
#include "../../Constant.hpp"
class TreeNode {
public:
	Tree *t;
	TreeNode *next;
};
class TreeNodeList {
public:
	TreeNodeList();
	void draw();
	void append(TreeNode *t);
	TreeNode *head;
	int size;
};

class Environment {
public:
	Environment();
	void draw();
	void reset();
	void setsolar(int time);
private:
	Pyramid *p;
	Ground *G;
	Tree *T;
	Tree *T2;
	Tree *T3;

	Solar *solar;

};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
