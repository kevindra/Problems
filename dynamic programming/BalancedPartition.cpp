/*
 * BalancedPartition.cpp
 * Input: n integers (range 0..k) A1,...An
 * Goal: partition into subsets S1 and S1
 * such that |sum(S1) - sum(s2)| is minimized.
 *
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */

/**
 * DP FORMULA:
 *
 * P(i,j) =  1 if some subset of {A1.. Ai} has a sum of j
 * 		  =  0 otherwise
 *
 * Recursive formula:
 * P(i,j) = 1 if P(i-1, j)=1 (already has sum of j)
 * 			  OR P(i-1, j-Ai)=1 (has a sum of j-Ai, so that
 * 			  					 we can add Ai now and make it j)
 *
 * O(n^2 * k) time
 *
 * How to minimize the sum difference?
 *
 * S = total sum of the integers divided by 2
 * Find the subset of array whose sum is as close as possible to S.
 *
 * first_partition_sum = Min { S - i : P(n,i) = 1 }
 * second_partition_sum = total_sum - first_partition_sum
 */
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void print(int **a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void balancedPartition(int *a, int n, int &p1, int &p2) {
	int total_sum = accumulate(a, a + n, 0);

	int **p = (int**) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		p[i] = (int*) malloc((total_sum + 1) * sizeof(int));

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= total_sum; j++)
			if (j <= a[i])
				p[i][j] = 1;
			else
				p[i][j] = 0;

	print(p, n, total_sum + 1);
	cout << endl;

	for (int j = 1; j <= total_sum; j++) {
		for (int i = 1; i < n; i++) {
			if (j - a[i] > 0)
				p[i][j] = max(p[i - 1][j], p[i - 1][j - a[i]]);
		}
	}

	print(p, n, total_sum + 1);

	int diff = INT_MAX;
	for (int i = 1; i <= total_sum; i++) {
		if (p[n - 1][i]) {
			if (abs(2 * i - total_sum) < diff) {
				diff = min(abs(2 * i - total_sum), diff);
				p1 = i;
			}
		}
	}
	p2 = total_sum - p1;
}

//int main() {
//	int a[] = { 2, 5, 3 }, n = 3;
//
//	int p1, p2;
//	balancedPartition(a, n, p1, p2);
//
//	cout << "Partition 1 sum: " << p1 << endl;
//	cout << "Partition 2 sum: " << p2 << endl;
//	return 0;
//}
