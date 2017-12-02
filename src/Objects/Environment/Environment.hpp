#ifndef SRC_OBJECTS_ENVIRONMENT_HPP_
#define SRC_OBJECTS_ENVIRONMENT_HPP_
#include <GL/glut.h>
#include "Ground.hpp"
#include "Solar.hpp"
#include "../Basic/Cylinder.hpp"
#include "../Basic/Cone.hpp"
#include "Mountain.hpp"

#include "Tree.hpp"
#include "../../Constant.hpp"
class TreeNode {
public:
	TreeNode(Tree *t);
	Tree *t;
	TreeNode *next;
};
class TreeNodeList {
public:
	TreeNodeList();
	void draw();
	void append(Tree *t);
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
	Mountain *mountain;
	Ground *G;
	//Tree *T;
	//Tree *T2;
	//Tree *T3;
	TreeNodeList *l;
	Solar *solar;

};




#endif /* SRC_OBJECTS_ENVIRONMENT_HPP_ */
