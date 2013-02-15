/*
 * AllSubset.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
using namespace std;

class PrintAllSubsets {
private:
	void printAllSubset(int *a, int n) {
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) > 0)
					cout << a[j] << ",";
			}
			cout << endl;
		}
	}
public:
	void run() {
		int n = 3;
		int *a = new int[n];

		for (int i = 0; i < n; i++)
			a[i] = i + 1;

		printAllSubset(a, n);
	}
};

