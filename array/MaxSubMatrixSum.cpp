/*
 * MaxSubMatrixSum.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>

using namespace std;

#define ROW 4
#define COL 4

class MaxSubMatrixSum {
private:
	int s[ROW][COL];
	void computeSumMatrix(int a[][COL], int r, int c) {
		for (int i = 0; i < r; i++)
			if (i == 0)
				s[i][0] = a[i][0];
			else
				s[i][0] = s[i - 1][0] + a[i][0];

		for (int j = 0; j < c; j++)
			if (j == 0)
				s[0][j] = a[0][j];
			else
				s[0][j] = s[0][j - 1] + a[0][j];

		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << s[i][j] << " ";
			cout << endl;
		}
	}

	int getSubmatSum(int r1, int c1, int r2, int c2) {
		if (r1 == 0 && c1 == 0)
			return s[r2][c2];
		if (r1 == 0)
			return s[r2][c2] - s[r2][c1 - 1];
		if (c1 == 0)
			return s[r2][c2] - s[r1 - 1][c2];
		return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
	}

	/**
	 * O(n^4) solution
	 */
	int getMaxSubmatSum(int a[][COL], int r, int c) {
		int maxsum = 0;
		for (int r1 = 0; r1 < r; r1++) {
			for (int c1 = 0; c1 < c; c1++) {
				for (int r2 = r1; r2 < r; r2++) {
					for (int c2 = c1; c2 < c; c2++) {
						int sum = getSubmatSum(r1, c1, r2, c2);
						maxsum = max(sum, maxsum);
					}
				}
			}
		}
		return maxsum;
	}

	/**
	 * O(n^3) solution
	 * ref = http://www.algorithmist.com/index.php/UVa_108
	 */
	int getMaxSubmatSum2(int a[][COL], int r, int c) {
		int globalmax = 0;

		for (int i = 0; i < r; i++)
			for (int j = i; j < r; j++) {
				int localmax = 0;
				for (int k = 0; k < c; k++) {
					localmax = max(localmax + getSubmatSum(i, k, j, k), 0);
					globalmax = max(localmax, globalmax);
				}
			}

		return globalmax;
	}

public:
	void run() {
		int a[ROW][COL]
		// = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
		// = { { -1, -2, -3, -4 }, { -5, -6, -7, -8 }, { -9, -10, -11, -12 }, {
		//  	-13, -14, -15, -16 } };
		= { { 0, -2, -7, 0 }, { 9, 2, -6, 2 }, { -4, 1, -4, 1 },
				{ -1, 8, 0, -2 } };

		computeSumMatrix(a, ROW, COL);

		cout << "SUM: " << getSubmatSum(0, 1, ROW - 1, COL - 1) << endl;

		cout << "Max Sum (O^4): " << getMaxSubmatSum(a, ROW, COL) << endl;
		cout << "Max Sum (O^3): " << getMaxSubmatSum2(a, ROW, COL) << endl;
	}
};

