/*
 * ExpressionEvaluator.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ExpressionEvaluator {
	struct node {
		int val;
		char op;
		node *left, *right;
	};

	node *createnew(int val, int op) {
		node *np = new node;
		np->val = val;
		np->op = op;
		np->left = np->right = NULL;
		return np;
	}

	bool isLeaf(node *root) {
		return root->left == NULL && root->right == NULL;
	}

	int evaluate(node *root) {
		if (isLeaf(root))
			return root->val;

		switch (root->op) {
		case '*':
			return evaluate(root->left) * evaluate(root->right);
		case '+':
			return evaluate(root->left) + evaluate(root->right);
		case '-':
			return evaluate(root->left) - evaluate(root->right);
		case '/':
			return evaluate(root->left) / evaluate(root->right);
		}
	}

	void print(node *root) {
		if (isLeaf(root)) {
			cout << root->val;
			return;
		}

		cout << "(";
		print(root->left);
		cout << " " << root->op << " ";
		print(root->right);
		cout << ")";
	}

	bool isOperator(char ch) {
		return (ch == '*' || ch == '+' || ch == '/' || ch == '-');
	}

public:
	void run() {
		node *root = createnew(0, '+');
		root->left = createnew(1, '\0');
		root->right = createnew(0, '*');
		root->right->left = createnew(2, '\0');
		root->right->right = createnew(3, '\0');

		print(root);
		cout << " = " << evaluate(root) << endl;
	}
};

