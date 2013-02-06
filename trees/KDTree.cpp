/*
 * KDTree.cpp
 * Resources:
 * 1. http://en.wikipedia.org/wiki/Kd-tree
 * 2. http://pointclouds.org/documentation/tutorials/kdtree_search.php
 *
 *  Created on: 03-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This is a simple implementation of kd tree where k = 2
 */
#define K 2
struct point {
	int a[K];

	/**
	 * pretty prints a point
	 */
	void print() {
		cout << " {" << a[0] << "," << a[1] << "}, ";
	}

	/**
	 * returns squared distance
	 */
	int squaredDistance(point p) {
		int dist = 0;
		for (int i = 0; i < K; i++)
			dist += (a[i] - p.a[i]) * (a[i] - p.a[i]);
		return dist;
	}
};

/**
 * get the partition key.
 * Partition key depends on the input axis.
 */
int partition(vector<point> &vp, int s, int e, int axis) {
	int pivot = e;
	int idx = s;
	for (int i = s; i < e; i++) {
		if (vp[i].a[axis] < vp[pivot].a[axis])
			swap(vp[idx], vp[i]), idx += 1; // swap the element with first open position
	}
	swap(vp[idx], vp[e]);
	return idx;
}

void kdtree(vector<point> &vp, int s, int e, int axis) {
	if (s > e)
		return;
	int pkey = partition(vp, s, e, axis);
	kdtree(vp, s, pkey - 1, (axis + 1) % 2);
	kdtree(vp, pkey + 1, e, (axis + 1) % 2);
}

point find_nearest(vector<point> vp, int s, int e, int axis, point p,
		point best) {
	if (s == e)
		return best;

	int mid = (s + e + 1) / 2; // e is 0-based
	vp[mid].print();
	cout << endl;

//	if (best == NULL) {
//		best = vp[mid];
//	}

	// consider the current node
	if (vp[mid].squaredDistance(best) < best.squaredDistance(p)) {
		best = vp[mid];
	}

	// search the near branch
	if (p.a[axis] < vp[mid].a[axis])
		best = find_nearest(vp, s, mid - 1, (axis + 1) % 2, p, best);
	// search the away branch - MAYBE
//	if () {
//
//	}
	return find_nearest(vp, mid + 1, e, (axis + 1) % 2, p, best);
}
//int main() {
//// (2,3), (5,4), (9,6), (4,7), (8,1), (7,2)
//	int x[] = { 2, 5, 9, 4, 8, 7 };
//	int y[] = { 3, 4, 6, 7, 1, 2 };
//	int n = 6;
//	vector<point> vp;
//	for (int i = 0; i < n; i++) {
//		point p;
//		p.a[0] = x[i], p.a[1] = y[i];
//		vp.push_back(p);
//	}
//
//	kdtree(vp, 0, n - 1, 0);
//
//	cout << "Array now: " << endl;
//	for (int i = 0; i < n; i++)
//		cout << " {" << vp[i].a[0] << ", " << vp[i].a[1] << "}, ";
//	cout << endl;
//
//	point p;
//	p.a[0] = 7;
//	p.a[1] = 3;
//
//	point nearestp = find_nearest(vp, 0, n - 1, 0, p);
//	cout << "Nearest: ";
//	nearestp.print();
//	cout << endl;
//	return 0;
//}
