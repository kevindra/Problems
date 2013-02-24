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

	/**
	 * Worst case O(n*logK)
	 */
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

	/**
	 * Returns median of list of size 5!
	 */
	int selectIdx(int *a, int s, int e, int k) {
		int n = 1 + (e - s);
		int *temp = new int[n];
		for (int i = 0; i < n; i++)
			temp[i] = a[s + i];

		sort(temp, temp + n);
		for (int i = 0; i < n; i++)
			if (a[s + i] == temp[n / 2])
				return s + i;

		return -1;
	}

	/**
	 * returns the approx median of the array, choose the median as pivot
	 */
	int medianOfMedians(int *a, int s, int e) {
		int numMedians = (e - s) / 5;

		for (int i = 0; i <= numMedians; i++) {
			// get the mediaans of the five-element subgroup
			int subStart = s + i * 5;
			int subRight = subStart + 4;
			if (subRight > e)
				subRight = e;
			int medianIdx = selectIdx(a, subStart, subRight, 2); // uses a faster method that works on lists of size 5
			// move the median to a contiguous block at the beginning of the list
			swap(a[s + i], a[medianIdx]);
		}
		//toString(a, e);
		// select the median from the contiguous block
		return numMedians / 2;
	}

	void toString(int *a, int n) {
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	/**
	 * Worst case O(n)
	 */

public:
	void run() {
		//int a[] = { 3, 3, 5, 4, 2, 1 }, n = 6;
		//int pivot = partition(a, 0, n - 1);

		//int k = 2;
		// int kth = getKthSmallestNumber(a, 0, n - 1, k);

		//for (int i = 0; i < n; i++)
		//	cout << a[i] << " ";

		//cout << "kth smallest: " << kth << endl;
		//cout << "Pivot: " << pivot << endl;

		int n = 100;
		int *a = new int[n];
		//int a[] = { 9, 0, 1, 3, 6, 2, 4, 7, 5, 8 };

		for (int i = 0; i < n; i++)
			a[i] = i;
		srand(unsigned(time(0)));
		random_shuffle(a, a + n);

//		cout << "Array: \n";
//		toString(a, n);
//		cout << endl;

		int mom = medianOfMedians(a, 0, n - 1);
		cout << "Median of median: " << mom << " : " << a[mom] << endl;
	}
};

