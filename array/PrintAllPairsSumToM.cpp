/*
 * PrintAllPairsSumToM.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class PrintAllPairsSumToM {
private:
	vector<pair<int, int> > getAllPairs(int *a, int n, int M) {
		int left = 0;
		int right = n - 1;

		vector<pair<int, int> > res;
		while (left < right) {
			if (a[left] + a[right] < M)
				left += 1;
			else if (a[left] + a[right] > M)
				right -= 1;
			else {
				pair<int, int> p = make_pair(left, right);
				res.push_back(p);
				left += 1;
				right -= 1;
			}
		}
		return res;
	}
public:
	void run() {
		int a[] = { 1, 2, 3, 4, 5 }, n = 5, M = 6;

		vector<pair<int, int> > res = getAllPairs(a, n, M);

		for (int i = 0; i < res.size(); i++)
			cout << a[res[i].first] << ", " << a[res[i].second] << endl;

	}
};

