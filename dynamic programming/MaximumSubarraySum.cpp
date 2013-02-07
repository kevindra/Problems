/*
 * MaximumSubarraySum.cpp
 *
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
using namespace std;

/*
 * using DP
 * O(n) time
 * O(n) space
 */
int maxSubarraySum(int *a, int n) {
	int *s = new int[n];

	s[0] = a[0];
	for (int i = 1; i < n; i++)
		s[i] = max(s[i - 1] + a[i], a[i]);

	return *max_element(s, s + n);
}

/*
 * non DP
 * O(n) time
 * O(1) space
 */
int maxSubarraySumKadane(int *a, int n) {
	int max_till_here = 0;
	int max_overall = 0;

	for (int i = 0; i < n; i++) {
		max_till_here = max(max_till_here + a[i], 0);
		max_overall = max(max_overall, max_till_here);
	}
	return max_overall;
}

int main() {
	int a[] = { 1, -2, 3 }, n = 3;

	cout << "Max subarray sum DP: " << maxSubarraySum(a, n) << endl;
	cout << "Max subarray sum Kadane: " << maxSubarraySumKadane(a, n) << endl;
	return 0;
}

