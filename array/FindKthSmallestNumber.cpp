/*
 * FindKthSmallestNumber.cpp
 * Find kth smallest number in an unsorted array of size n. (k < n)
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

class FindKthSmallestNumber {
private:
	int partition(int *a, int s, int e) {
		int pivot = s;
		int left = s;
		int right = e;

		while (left <= right) {
			while (left <= right && a[left] <= a[pivot])
				++left;
			while (left <= right && a[right] >= a[pivot])
				--right;
			if (left < right) {
				swap(a[left], a[right]);
			}
		}
		swap(a[pivot], a[right]);
		return left - 1;
	}

	int getKthSmallestNumber(int *a, int s, int e, int k) {
		if (s > e)
			return -1;

		int pivot = partition(a, s, e);

		if (pivot + 1 == k) {
			return a[pivot];
		} else if (pivot + 1 < k) {
			return getKthSmallestNumber(a, pivot + 1, e, k);
		} else {
			return getKthSmallestNumber(a, s, pivot - 1, k);
		}
	}

public:
	void run() {
		int a[] = { 3, 3, 5, 4, 2, 1 }, n = 6;
		//int pivot = partition(a, 0, n - 1);

		int k = 2;
		int kth = getKthSmallestNumber(a, 0, n - 1, k);

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << "kth smallest: " << kth << endl;
		//cout << "Pivot: " << pivot << endl;
	}
};

