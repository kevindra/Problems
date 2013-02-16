/*
 * Print2DSpiral.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>
using namespace std;

class Print2DSpiral {
private:
	bool isbetween(int i, int min, int max) {
		return (i >= min) && (i < max);
	}
	void goSpiral(int **a, int r, int c) {
		bool **flag = (bool**) malloc(r * sizeof(bool));
		for (int i = 0; i < r; i++)
			flag[i] = (bool*) malloc(c * sizeof(bool));

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				flag[i][j] = true;

		int di[4] = { 0, 1, 0, -1 };
		int dj[4] = { 1, 0, -1, 0 };

		int count = 0;
		int dir = 0;
		int i = 0, j = 0;

		while (count < r * c) {
			if (isbetween(i, 0, r) && isbetween(j, 0, c) && flag[i][j]) {
				flag[i][j] = false;
				cout << a[i][j] << " ";
				i += di[dir];
				j += dj[dir];
				count++;
			} else {
				i -= di[dir];
				j -= dj[dir];
				dir = (dir + 1) % 4;
				i += di[dir];
				j += dj[dir];
			}
		}
	}
public:
	void run() {
		int r = 4, c = 4;
		int **a = (int**) malloc(r * sizeof(int));
		for (int i = 0; i < r; i++)
			a[i] = (int*) malloc(c * sizeof(int));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << (a[i][j] = i * r + j) << " ";
			cout << endl;
		}

		cout << "Spiral: " << endl;
		goSpiral(a, r, c);
	}
};
