/*
 * BinaryTree.cpp
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

bst *BST::new_bst_node(int val) {
	bst *np = new bst;
	np->val = val;
	np->left = NULL;
	np->right = NULL;
	return np;
}

void insert_in_bst_inner(bst *&root, int x) {
	if (root == NULL) {
		root = BST::new_bst_node(x);
		return;
	}

	if (x < root->val)
		insert_in_bst_inner(root->left, x);
	else if (x >= root->val)
		insert_in_bst_inner(root->right, x);
}
void BST::insert_in_bst(int x) {
	insert_in_bst_inner(root, x);
}
void inorder_inner(bst *root) {
	if (root == NULL)
		return;
	inorder_inner(root->left);
	cout << root->val << " ";
	inorder_inner(root->right);
}

void BST::inorder() {
	inorder_inner(this->root);
}

bst *BST::get_root() {
	return this->root;
}
