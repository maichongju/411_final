#include "Environment.hpp"
Environment::Environment() {
	G = new Ground();
	/////
	l = new TreeNodeList();
	Tree *n1a = new Tree(1, 0, -.6, .2, .5, .2, TREE_CONE);
	Tree *n1b = new Tree(1, 0, -1, TREE_SPHERE);
	Tree *n1c = new Tree(1, 0, -1.50, TREE_CONE);
	Tree *n1d = new Tree(1, 0, -2, TREE_SPHERE);
	Tree *n1e = new Tree(1, 0, -2.5, TREE_SPHERE);
	Tree *n5a = new Tree(1.4, 0, -1.1, TREE_SPHERE);
	Tree *n5b = new Tree(1.4, 0, -1.5, .2, .5, .2, TREE_CONE);
	Tree *n5c = new Tree(1.4, 0, -1.9, TREE_SPHERE);
	Tree *n5d = new Tree(1.4, 0, -2.1, TREE_CONE);
	Tree *n5e = new Tree(1.4, 0, -.6, TREE_SPHERE);
	Tree *n5f = new Tree(1.4, 0, -2.5, TREE_SPHERE);
	Tree *n5g = new Tree(1.4, 0, -2.8, .2, .5, .2, TREE_CONE);
	Tree *n6a = new Tree(.6, 0, -.5, TREE_SPHERE);
	Tree *n6b = new Tree(.60, 0, -1, TREE_SPHERE);
	Tree *n6c = new Tree(.60, 0, -1.5, TREE_CONE);
	Tree *n6d = new Tree(.6, 0, -2, TREE_SPHERE);
	Tree *n6e = new Tree(.60, 0, -2.4, .2, .5, .2, TREE_CONE);
	Tree *n6f = new Tree(.60, 0, -2.85, TREE_SPHERE);
	Tree *n7a = new Tree(1.8, 0, -1.1, TREE_CONE);
	Tree *n7b = new Tree(1.8, 0, -1.5, TREE_SPHERE);
	Tree *n7c = new Tree(1.8, 0, -1.9, TREE_CONE);
	Tree *n7d = new Tree(1.8, 0, -2.1, TREE_SPHERE);
	Tree *n7e = new Tree(1.8, 0, -.6, TREE_CONE);
	Tree *n7f = new Tree(1.8, 0, -2.5, TREE_SPHERE);
	Tree *n7g = new Tree(1.8, 0, -2.8, .2, .5, .2, TREE_CONE);
	Tree *n8a = new Tree(2.2, 0, -1.1, TREE_SPHERE);
	Tree *n8b = new Tree(2.2, 0, -1.5, TREE_CONE);
	Tree *n8c = new Tree(2.2, 0, -1.9, TREE_SPHERE);
	Tree *n8d = new Tree(2.2, 0, -2.1, TREE_CONE);
	Tree *n8e = new Tree(2.2, 0, -.6, .2, .5, .2, TREE_CONE);
	Tree *n8f = new Tree(2.2, 0, -2.5, TREE_SPHERE);
	Tree *n8g = new Tree(2.2, 0, -2.8, TREE_CONE);
	Tree *n9a = new Tree(2.6, 0, -1.1, TREE_SPHERE);
	Tree *n9b = new Tree(2.6, 0, -1.5, .2, .5, .2, TREE_CONE);
	Tree *n9c = new Tree(2.6, 0, -1.9, TREE_SPHERE);
	Tree *n9d = new Tree(2.6, 0, -2.1, TREE_CONE);
	Tree *n9e = new Tree(2.6, 0, -.6, TREE_CONE);
	Tree *n9f = new Tree(2.6, 0, -2.5, TREE_SPHERE);
	Tree *n9g = new Tree(2.6, 0, -2.8, .2, .5, .2, TREE_CONE);

	l->append(n1a);
	l->append(n1b);
	l->append(n1c);
	l->append(n1d);
	l->append(n1e);
	l->append(n5a);
	l->append(n5b);
	l->append(n5c);
	l->append(n5d);
	l->append(n5e);
	l->append(n5f);
	l->append(n5g);
	l->append(n6a);
	l->append(n6b);
	l->append(n6c);
	l->append(n6d);
	l->append(n6e);
	l->append(n6f);
	l->append(n7a);
	l->append(n7b);
	l->append(n7c);
	l->append(n7d);
	l->append(n7e);
	l->append(n7f);
	l->append(n7g);
	l->append(n8a);
	l->append(n8b);
	l->append(n8c);
	l->append(n8d);
	l->append(n8e);
	l->append(n8f);
	l->append(n8g);
	l->append(n9a);
	l->append(n9b);
	l->append(n9c);
	l->append(n9d);
	l->append(n9e);
	l->append(n9f);
	l->append(n9g);
	////
	Tree *nn = new Tree(-1, 0, 1, TREE_CONE);
	Tree *nn2 = new Tree(-.6, 0, 1, TREE_SPHERE);
	Tree *nn3 = new Tree(-.8, 0, .8, .2, .5, .2, TREE_CONE);
	Tree *nna = new Tree(-1, 0, 1 + .8, TREE_SPHERE);
	Tree *nn2a = new Tree(-.6, 0, 1 + .8, TREE_CONE);
	Tree *nn3a = new Tree(-.8, 0, .8 + .8, TREE_SPHERE);
	Tree *nnb = new Tree(-1, 0, 1 + 1.6, TREE_CONE);
	Tree *nn2b = new Tree(-.6, 0, 1 + 1.6, TREE_SPHERE);
	Tree *nn3b = new Tree(-.8, 0, .8 + 1.6, .2, .5, .2, TREE_CONE);
	Tree *nnc = new Tree(-1.25, 0, .5, TREE_CONE);
	Tree *nn2c = new Tree(-2.3, 0, .5, TREE_SPHERE);
	Tree *nnd = new Tree(-1 - 1, 0, 1 + .4, TREE_CONE);
	Tree *nn2d = new Tree(-.6 - 1, 0, 1 + .4, TREE_SPHERE);
	Tree *nn3d = new Tree(-.8 - 1, 0, .8 + .4, TREE_CONE);
	Tree *nne = new Tree(-1 - 1, 0, 1 + 1.2, TREE_SPHERE);
	Tree *nn2e = new Tree(-.6 - 1, 0, 1 + 1.2, .2, .5, .2, TREE_CONE);
	Tree *nn3e = new Tree(-.8 - 1, 0, .8 + 1.2, TREE_SPHERE);
	Tree *nn2f = new Tree(-.6 - 1, 0, .5, TREE_CONE);
	Tree *nn3f = new Tree(-.8 - 1, 0, .5, TREE_SPHERE);
	Tree *nng = new Tree(-1 - 1.9, 0, 1 + .4, TREE_CONE);
	Tree *nn2g = new Tree(-.6 - 1.9, 0, 1 + .4, TREE_SPHERE);
	Tree *nn3g = new Tree(-.8 - 1.9, 0, .8 + .4, TREE_CONE);
	Tree *nnh = new Tree(-1 - 1.9, 0, 1 + 1.2, TREE_SPHERE);
	Tree *nn2h = new Tree(-.6 - 1.9, 0, 1 + 1.2, TREE_SPHERE);
	Tree *nn3h = new Tree(-.8 - 1.9, 0, .8 + 1.2, TREE_CONE);
	l->append(nn);
	l->append(nn2);
	l->append(nn3);
	l->append(nna);
	l->append(nn2a);
	l->append(nn3a);
	l->append(nnb);
	l->append(nn2b);
	l->append(nn3b);
	l->append(nnc);
	l->append(nn2c);
	l->append(nnd);
	l->append(nn2d);
	l->append(nn3d);
	l->append(nne);
	l->append(nn2e);
	l->append(nn3e);
	l->append(nn2f);
	l->append(nn3f);
	l->append(nng);
	l->append(nn2g);
	l->append(nn3g);
	l->append(nnh);
	l->append(nn2h);
	l->append(nn3h);
	solar = new Solar();
	mountain = new Mountain(-2.8,0,-2.8);
	mountain->scale(1.3);
	mountain->setTextureID(TEXTURE_PYRAMID);

}
TreeNode::TreeNode(Tree *t) {
	this->t = t;
	next = NULL;
}
TreeNodeList::TreeNodeList() {
	this->head = NULL;
	size = 0;
}
void TreeNodeList::append(Tree *t) {
	TreeNode *n = new TreeNode(t);
	TreeNode *current;

	if (size == 0) {
		this->head = n;
	} else {

		for (current = this->head; current->next != NULL;
				current = current->next) {
		}
		current->next = n;
	}
	size++;
}
void TreeNodeList::draw() {
	if (size != 0) {
		TreeNode *n;
		for (n = this->head; n != NULL; n = n->next) {
			n->t->draw();
		}
	}
}
void Environment::draw() {
	G->draw();
	l->draw();
	solar->draw();
	mountain->draw();
}

void Environment::setsolar(int time) {
	this->solar->settime(time);
}

void Environment::reset() {

}

