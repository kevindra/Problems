/*
 * IterativePostOrder.cpp
 *
 *  Created on: 24-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class IterativePostOrder {
private:
	struct node {
		int n;
		node *left, *right;
	};

	node *createnewnode(int n) {
		node *np = new node;
		np->n = n;
		np->left = np->right = NULL;
		return np;
	}

	void postorder(node *root) {
		if (root != NULL) {
			postorder(root->left);
			postorder(root->right);
			cout << root->n << " ";
		}
	}

	void postorderIterative(node *root) {
		stack<node*> s1, s2;
		s1.push(root);

		while (!s1.empty()) {
			node *t = s1.top();
			s1.pop();

			s2.push(t);
			if (t->left != NULL)
				s1.push(t->left);
			if (t->right != NULL)
				s1.push(t->right);
		}

		while (!s2.empty()) {
			node *t = s2.top();
			s2.pop();
			cout << t->n << " ";
		}
	}

public:
	void run() {
		node *root = createnewnode(1);
		root->left = createnewnode(2);
		root->right = createnewnode(5);
		root->left->left = createnewnode(3);
		root->left->right = createnewnode(4);
		root->right->left = createnewnode(6);
		root->right->right = createnewnode(7);

		cout << "Recursive post-order: ";
		postorder(root);
		cout << endl;

		cout << "Iterative post-order: ";
		postorderIterative(root);
		cout << endl;
	}
};

