/*
 * MakingChange.cpp
 *
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */

/**
 * You are given n types of coin denominations of values v(1) < v(2) < ... < v(n) (all integers).
 * Assume v(1) = 1,
 * so you can always make change for any amount of money C.
 * Give an algorithm which makes change for an amount of money C with as few coins as possible.
 */
#include <iostream>

using namespace std;

class MakingChange {
private:
	int minCoins(int *coins, int n, int C) {
		int *s = new int[C];
		for (int i = 0; i < C + 1; i++)
			s[i] = 0;

		s[1] = 1;
		for (int i = 1; i < C + 1; i++) {
			int minCoins = INT_MAX;
			for (int j = 0; j < n; j++) {
				if (i - coins[j] >= 0)
					minCoins = min(s[i - coins[j]] + 1, minCoins);
			}
			s[i] = minCoins;
		}

		for (int i = 0; i < C + 1; i++)
			cout << i << ": " << s[i] << endl;

		return s[C];
	}
public:
	void run() {
		int a[] = { 1, 2, 3, 15 }, n = 4, C = 18;
		cout << "Min coins reqd: " << minCoins(a, n, C) << endl;
	}
};

