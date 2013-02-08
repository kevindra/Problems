/*
 * SpellCheckerUsingBKTree.cpp
 *
 * Resources:
 * 1. http://blog.notdot.net/2007/4/Damn-Cool-Algorithms-Part-1-BK-Trees
 * 2. http://hamberg.no/erlend/posts/2012-01-17-BK-trees.html
 * 3. https://github.com/sholiday/cppBKTree/blob/master/BKNode.h
 *
 * Background:
 *
 * A BK-Tree is a really cool data structure for building a “dictionary”
 * of similar words. It can be used to guess that you meant “cat” when you
 * wrote “cta”. It works by building a tree with words from a dictionary
 * by using the first word as a root node and then attaching subsequent
 * words with a branch of length d(root_word, new_word) where d is a function
 * for finding the “distance” between two words.
 *
 *  Created on: 09-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define MAX_DISTANCE 50

class BKTree {
private:
	struct node {
		string s;
		node *link[MAX_DISTANCE];
	};

	node *root;

	node *createNewNode(string s) {
		node *np = new node;
		np->s = s;

		for (int i = 0; i < MAX_DISTANCE; i++)
			np->link[i] = NULL;
		return np;
	}

	// normal edit distance method
	// returns edit distance between two string s1 and s2
	int editDistance(string s1, string s2) {
		int sz1 = s1.size(), sz2 = s2.size();

		if (sz1 == 0)
			return sz2;
		if (sz2 == 0)
			return sz1;

		// initialize the matrix
		int **m = (int**) malloc((sz1 + 1) * sizeof(int));
		for (int i = 0; i <= sz1; i++)
			m[i] = (int*) malloc((sz2 + 1) * sizeof(int));

		for (int i = 0; i <= sz1; i++)
			m[i][0] = i;
		for (int i = 0; i <= sz2; i++)
			m[0][i] = i;

		for (int i = 1; i <= sz1; i++) {
			for (int j = 1; j <= sz2; j++) {
				m[i][j] = min(m[i - 1][j] + 1,
						min(m[i][j - 1] + 1,
								m[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])));
			}
		}
		return m[sz1][sz2];
	}

	// inserts in the BK tree
	void insertInTree(node *&r, string s) {
		// if the node is null
		// create a node there
		if (r == NULL) {
			r = createNewNode(s);
			return;
		}

		// if not
		// then calculate the distance of new string with the node string
		int d = editDistance(s, r->s);

		// insert in the distance 'd' branch
		insertInTree(r->link[d], s);
	}

	// for simplicity
	// BSF to print the tree level wise
	void print(node *r) {
		if (r == NULL)
			return;

		queue<node *> q;
		q.push(r);
		while (!q.empty()) {
			node *n = q.front();
			q.pop();

			if (n == NULL) {
				cout << endl;
				continue;
			} else
				cout << n->s << " ";

			q.push(NULL);
			for (int i = 0; i < MAX_DISTANCE; i++)
				if (n->link[i])
					q.push(n->link[i]);
		}
		cout << endl;
	}

	// search method
	//
	vector<string> search(node *r, string s, int threshold) {
		int d = editDistance(r->s, s);

		vector<string> v;
		if (d <= threshold)
			v.push_back(r->s);

		int dmin = abs(d - threshold);
		int dmax = d + threshold;

		cout << r->s << " " << s << ": " << d << " [" << dmin << "," << dmax
				<< "] \n";

		for (int i = dmin; i <= dmax; i++) {
			if (r->link[i]) {
				vector<string> subv = search(r->link[i], s, threshold);
				v.insert(v.end(), subv.begin(), subv.end());
			}
		}
		return v;
	}
public:
	BKTree() {
		root = NULL;
	}
	~BKTree() {
		root = NULL;
	}
	void insert(string s) {
		insertInTree(root, s);
	}

	void run() {
		string dictionary[] = { "cat", "cut", "hat", "man", "hit", "people",
				"sheep", "conspiracy" };
		int n = 8;

		for (int i = 0; i < n; i++) {
			insert(dictionary[i]);
		}

		cout << "Tree: " << endl;
		print(root);
		cout << endl;

		vector<string> v = search(root, "peepple", 3);
		cout << "Matched correct spellings: ";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;

		v = search(root, "cunsperricy", 4);
		cout << "Matched correct spellings: ";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
};
