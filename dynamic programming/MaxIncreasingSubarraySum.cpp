/*
 * MaxIncreasingSubarraySum.cpp
 *
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
using namespace std;

/**
 * max sum increasing subsequence in an array.
 * only for positive numbers
 */
int maxIncreasingSubarraySumPositiveNumbers(int *a, int n) {
	int *s = new int[n];

	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			s[i] = s[i - 1] + a[i];
		else
			s[i] = a[i];
	}

	return *max_element(s, s + n);
}

int maxIncreasingSubarraySumAllNumbers(int *a, int n) {
	int *s = new int[n];

	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			s[i] = max(s[i - 1] + a[i], a[i]);
		else
			s[i] = a[i];
	}

	return *max_element(s, s + n);
}

//int main() {
//	int a[] = { 4, 3, 2, 0, -2, 4, 5 }, n = 7;
//
//	cout << "Max Increasing Subarray Sum (only +ve nums): "
//			<< maxIncreasingSubarraySumPositiveNumbers(a, n) << endl;
//
//	cout << "Max Increasing Subarray Sum (all): "
//			<< maxIncreasingSubarraySumAllNumbers(a, n) << endl;
//	return 0;
//}

