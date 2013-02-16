/*
 * FindRotationIndex.cpp
 *
 *  Created on: 16-Feb-2013
 *      Author: Kevindra
 */

/**
 * Find how many times a sorted array is rotated.
 */
#include <iostream>

using namespace std;

class FindRotationIndex {
private:
	int getRotationIndex(int *a, int s, int e) {
		// this would come true, only when the array is sorted
		if (s > e)
			return 0;

		cout << s << ":" << e << endl;

		// if the array is already sorted
		if (a[s] < a[e])
			return e + 1;

		int mid = (s + e) / 2;

		// if we found the mid as the rotated index.
		if (a[s] <= a[mid] && a[mid + 1] <= a[e])
			return mid + 1;

		if (a[mid] <= a[e])
			return getRotationIndex(a, s, mid - 1);
		else
			return getRotationIndex(a, mid + 1, e);
	}
public:
	void run() {
		int a[] = { 7, 8, 9, 1, 2, 3, 4, 5, 6 }, n = 9;

		cout << "Rotation Index: " << getRotationIndex(a, 0, n - 1) << endl;
	}
};

