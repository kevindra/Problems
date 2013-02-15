/*
 * PrintAllValidCombinationsOfBrackets.cpp
 *
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */
#include<iostream>
#include<string>

using namespace std;

class PrintAllValidCombinationsOfBrackets {
	void print(int open, int closed, string s) {
		if (open == 0 && closed == 0) {
			cout << s << endl;
			return;
		}

		if (open > closed)
			return;

		if (open > 0)
			print(open - 1, closed, s + "(");
		if (closed > 0)
			print(open, closed - 1, s + ")");
	}
public:
	void run() {
		int n = 5;
		cout << "N = " << n << endl;
		print(n, n, "");
	}
};

