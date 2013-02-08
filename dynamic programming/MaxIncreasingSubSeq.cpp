/*
 * MaxIncreasingSubSeq.cpp
 *
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

/**
 * Problem statement:
 * Find length of max strictly increasing sub seq not necessarily contiguous.
 */
class MaxIncreasingSubSeq {
public:

	/**
	 * using DP,
	 * O(n^2) time complexity
	 */
	int maxIncreasingSubSeq(int *a, int n) {
		int *s = new int[n]; // s[i] = max length of increasing subseq ending at i

		for (int i = 0; i < n; i++)
			s[i] = 1;

		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[j] < a[i])
					s[i] = max(s[j] + 1, s[i]);
			}
		}

		return *max_element(s, s + n);
	}

	void run() {
		int a[] = { 2, 0, 3, 0, 4, 5 }, n = 6;
		cout << "Max Inc Sub Seq length: " << maxIncreasingSubSeq(a, n) << endl;
	}
};

