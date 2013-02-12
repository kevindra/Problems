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
	void permuteAll(int n, int sum, vector<int> v) {
		if (sum == 0) {
			for (unsigned int i = 0; i < v.size(); i++)
				cout << v[i] << ",";
			cout << endl;
			return;
		}

		if (sum < 0)
			return;

		for (int i = 1; i < n; i++) {
			v.push_back(i);
			permuteAll(n, sum - i, v);
			v.pop_back();
		}
	}

	void permute(int n) {
		vector<int> v;
		permuteAll(n, n, v);
	}

	void run() {
		permute(4);
	}
};

