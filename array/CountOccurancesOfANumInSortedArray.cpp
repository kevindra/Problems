/*
 * CountOccurancesOfANumInSortedArray.cpp
 *
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>

using namespace std;

class CountOccurancesOfANumInSortedArray {
private:
	int binsearch(int *a, int s, int e, int x, bool wantLeftMostOccurrance) {
		if (s > e)
			return -1;

		int mid = (s + e) / 2;

		if (a[mid] < x)
			return binsearch(a, mid + 1, e, x, wantLeftMostOccurrance);
		else if (a[mid] > x)
			return binsearch(a, s, mid - 1, x, wantLeftMostOccurrance);
		else {
			// a little tweak here
			if (wantLeftMostOccurrance) {
				if (mid > 0 && a[mid] == a[mid - 1])
					return binsearch(a, s, mid - 1, x, wantLeftMostOccurrance);
				else
					return mid;
			} else {
				if (mid < e && a[mid] == a[mid + 1])
					return binsearch(a, mid + 1, e, x, wantLeftMostOccurrance);
				else
					return mid;
			}
		}
	}

	// another approach
	// worst case is O(n) - when all elements are duplicate
	int getOccurences(int *a, int s, int e, int x) {
		if (s > e)
			return 0;

		int mid = (s + e) / 2;
		if (x < a[mid])
			return getOccurences(a, s, mid - 1, x);
		else if (x > a[mid])
			return getOccurences(a, mid + 1, e, x);
		else
			return 1 + getOccurences(a, s, mid - 1, x)
					+ getOccurences(a, mid + 1, e, x);
	}
public:
	void run() {
		int a[] = { 1, 2, 2, 2, 3, 4 }, n = 6;
		int x = 2;

		int leftMostIndex = binsearch(a, 0, n - 1, x, true);
		int rightMostIndex = binsearch(a, 0, n - 1, x, false);

		cout << "No. of occurances: "
				<< ((leftMostIndex == -1) ?
						0 : (rightMostIndex - leftMostIndex + 1)) << endl;

		cout << "Method 2: all occurences: " << getOccurences(a, 0, n - 1, x)
				<< endl;
	}
};

