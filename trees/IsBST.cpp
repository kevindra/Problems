/*
 * IsBST.cpp
 *	http://leetcode.com/2010/09/determine-if-binary-tree-is-binary.html
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */
#include<iostream>
#include "../lib/BinaryTree.h"

using namespace std;

/**
 * this method is using min-max range for each node.
 */
bool isBST(bst *root, int min, int max) {
	if (root == NULL)
		return true;

	if (root->val >= min && root->val <= max)
		return true && isBST(root->left, min, root->val)
				&& isBST(root->right, root->val, max);
	return false;
}

//int main() {
//	int a[] = { 10, 5, 15, 20 }, n = 4;
//
//	bst *root = NULL;
//	for (int i = 0; i < n; i++)
//		insert_in_bst(root, a[i]);
//
//	// make it non-bst
//	root->right->left = new_bst_node(6);
//
//	cout << "Tree is : ";
//	inorder(root);
//
//	cout << " Is a BST: " << isBST(root, INT_MIN, INT_MAX) << endl;
//	return 0;
//}
