/*
 * PermuteAllSequences.cpp
 * http://www.careercup.com/question?id=15290675
 *
 *  Created on: 10-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <vector>

using namespace std;

class PermuteAllSequences {
public:
	void permuteAll(int *a, int n, int sum, vector<int> v) {
		if (sum == 0) {
			for (unsigned int i = 0; i < v.size(); i++)
				cout << v[i] << ",";
			cout << endl;
			return;
		}

		if (sum < 0)
			return;

		for (int i = 0; i < n; i++) {
			v.push_back(a[i]);
			permuteAll(a, n, sum - a[i], v);
			v.pop_back();
		}
	}

	void permute(int n) {
		int *a = new int;
		for (int i = 0; i < n - 1; i++)
			a[i] = i + 1;

		vector<int> v;
		permuteAll(a, n - 1, n, v);
	}

	void run() {
		permute(5);
	}
};

