/*
 * PrintAllMakingChangeSet.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */

/**
 * Given a change amount, print all possible combinations using different sets of coins.
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class PrintAllMakingChangeSet {
private:
	void printAllBruteForce(int *coins, int n, int change) {
		for (int i = 0; i < (1 << n); i++) {
			vector<int> c;
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) > 0) {
					sum += coins[j];
					c.push_back(coins[j]);
				}
			}
			if (sum == change) {
				for (int i = 0; i < c.size(); i++)
					cout << c[i] << " ";
				cout << endl;
			}
		}
	}

	int getCountOfChangeSet(int *coins, int n, int change) {
		int *c = new int[change + 1];
		for (int i = 0; i < change + 1; i++)
			c[i] = 0;

		for (int i = 0; i < n; i++)
			c[coins[i]] = 1;

		print(c, change + 1);

		for (int i = 1; i < change + 1; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (i - coins[j] > 0)
					c[i] += 1;
			}
			print(c, change + 1);
		}
		return c[change];
	}

	void print(int *a, int n) {
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << ",";
		cout << endl;
	}
public:
	void run() {
		int a[] = { 1, 2, 3 }, n = 3, change = 5;
		printAllBruteForce(a, n, change);

		cout << endl;
		cout << "No. of coins sets who can sum upto " << change << " : "
				<< getCountOfChangeSet(a, n, change) << endl;
	}
};

