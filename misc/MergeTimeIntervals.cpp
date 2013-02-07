/*
 * MergeTimeIntervals.cpp
 *	Given a list of time intervals. A time interval is a pair of start and end time (s,e).
 *	These time intervals are disjoint and sorted by start time.
 *	Write a method to merge one more input time interval in the list.
 *
 *  Created on: 07-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

struct Interval {
	int s, e;
};

Interval *merge(Interval *a, int &n, Interval input) {

	Interval *o = new Interval[10];

	bool started = false;
	bool finished = false;
	bool startedOutside = false;

	Interval mergedInterval;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (finished) {
			o[idx] = a[i];
			idx += 1;
			continue;
		}

		if (!started) {
			if (input.s < a[i].s) {
				mergedInterval.s = input.s;
				started = true;
				startedOutside = true;
			} else if (input.s >= a[i].s && input.s <= a[i].e) {
				cout << "a[i]: " << a[i].s << endl;
				mergedInterval.s = a[i].s;
				started = true;
			} else {
				o[idx] = a[i];
				idx += 1;
			}
		}
		if (started) {
			if (input.e < a[i].s) {
				mergedInterval.e = input.e;
				o[idx] = mergedInterval;
				idx += 1;
				i -= 1; // to create a seperate interval
				finished = true;
			} else if (input.e >= a[i].s && input.e <= a[i].e) {
				cout << "a[i]: " << a[i].e << endl;

				if (startedOutside) {
					mergedInterval.e = a[i].e;
					o[idx] = mergedInterval;
					idx += 1;
				}
				finished = true;
			}
		}
	}

	if (started) {
		mergedInterval.e = input.e;
		o[idx] = mergedInterval;
		idx += 1;
	}

	n = idx;
	return o;
}

//int main() {
//	int n = 2;
//	Interval a[2] = { { 1, 4 }, { 8, 11 } };
//	Interval input = { 9, 10 };
//
//	for (int i = 0; i < n; i++) {
//		cout << "(" << a[i].s << "," << a[i].e << "), ";
//	}
//	cout << endl;
//
//	Interval *output = merge(a, n, input);
//
//	cout << "Output after merging: (" << input.s << "," << input.e << ") "
//			<< endl;
//	for (int i = 0; i < n; i++) {
//		cout << "(" << output[i].s << "," << output[i].e << "), ";
//	}
//	cout << endl;
//	return 0;
//}

