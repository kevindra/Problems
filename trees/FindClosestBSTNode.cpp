/*
 * FindClosestBSTNode.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>

using namespace std;

class FindClosestBSTNode {
private:
	struct node {
		int val;
		node *left, *right;
	};

	node *createnew(int val) {
		node *np = new node;
		np->val = val;
		np->left = NULL;
		np->right = NULL;
		return np;
	}

	void insert(node *&root, int val) {
		if (root == NULL) {
			root = createnew(val);
			return;
		}

		if (val < root->val)
			insert(root->left, val);
		else
			insert(root->right, val);
	}

	void inorder(node *root) {
		if (root != NULL) {
			inorder(root->left);
			cout << root->val << " ";
			inorder(root->right);
		}
	}

	int findClosest(node *root, int x) {
		if (root == NULL)
			return INT_MAX;

		int diff = abs(root->val - x);

		if (x < root->val)
			return min(diff, findClosest(root->left, x));
		else if (x > root->val)
			return min(diff, findClosest(root->right, x));
		else
			return 0;
	}
public:
	void run() {
		int a[] = { 5, 3, 8, 1, 4, 7 }, n = 6;
		node *root = NULL;
		for (int i = 0; i < n; i++)
			insert(root, a[i]);

		cout << "inorder: ";
		inorder(root);
		cout << endl;

		int x = -5;
		cout << "Closest: " << abs(abs(x) - findClosest(root, x)) << endl;
	}
};

