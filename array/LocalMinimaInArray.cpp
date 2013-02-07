/*
 * LocalMinimaInArray.cpp
 *
 *  Created on: 06-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>


using namespace std;

int localMinima(int a[], int s, int e, int n) {
	if (s > e)
		return -1;

	if (n == 1)
		return 0;
	if (n == 2)
		return (a[0] < a[1]) ? a[0] : a[1];

	int mid = (s + e) / 2;

	// left boundary condition
	if (mid == 0) {
		return (a[mid] < a[mid + 1]) ? mid : -1;
	}

	// right boundary condition
	if (mid == n - 1) {
		return (a[mid] < a[mid - 1]) ? mid : -1;
	}

	// if local minima
	if (a[mid - 1] > a[mid] && a[mid] < a[mid + 1]) {
		return mid;
	}

	// if no local minima yet,toss the half array out
	if (a[mid - 1] < a[mid + 1])
		return localMinima(a, s, mid - 1, n);
	return localMinima(a, mid + 1, e, n);
}
//int main() {
//	int a[] = {1,3,5,7,9,11,10,1,8,1}, n = 10;
//
//	int lm = localMinima(a, 0, n-1, n);
//	if(lm == -1) cout<<"Couldn't find any local minima in the array";
//	else cout <<" Found local minima at: a[" << lm << "] = " << a[lm];
//	return 0;
//}
//
