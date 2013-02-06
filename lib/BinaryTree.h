/*
 * BinaryTree.h
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>

using namespace std;

struct bst {
	int val;
	bst *left;
	bst *right;
};

class BST {
private:
	bst *root;
public:
	static bst *new_bst_node(int);
	void BST::insert_in_bst(int x);
	void BST::inorder();
	bst *get_root();
};


#endif /* BINARYTREE_H_ */
