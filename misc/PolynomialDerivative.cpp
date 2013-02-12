/*
 * DerivativeOfPolynomial.cpp
 *
 *  Created on: 12-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>
#include <algorithm>
using namespace std;

class PolynomialDerivative {
private:
	struct node {
		int coef;
		int exp;
	};

	node *createNewNode(int coef, int exp) {
		node *n = new node;
		n->coef = coef;
		n->exp = exp;
		return n;
	}

	void print(node p[], int n) {
		for (int i = 0; i < n; i++) {
			if (p[i].coef == 0)
				continue;
			if (p[i].exp == 0)
				cout << p[i].coef << endl;
			else
				cout << p[i].coef << "*X^" << p[i].exp << " + ";
		}
	}
	void derive(node p[], int n) {
		for (int i = 0; i < n; i++) {
			p[i].coef *= p[i].exp;
			p[i].exp = (p[i].exp == 0) ? 0 : p[i].exp - 1;
		}
		cout << "After derivation: ";
		print(p, n);
	}
public:
	void run() {
		int n = 3;
		node p[3] = { { 2, 2 }, { 3, 1 }, { 5, 0 } };
		print(p, n);
		derive(p, n);

	}
};

