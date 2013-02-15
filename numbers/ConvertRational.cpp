/*
 * ConvertRational.cpp
 *
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

class ConvertRational {
private:
	int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	void convertRational(double num, int &p, int &q) {
		int f = 1;

		// 0.00001 is max allowed precision
		while ((double) (num * f) - (int) (num * f) > 0.00001) {
			f *= 10;
		}

		int g = gcd(f, (int) (num * f));

		p = (int) (num * f) / g;
		q = f / g;
	}
public:
	void run() {
		double num = 0.133;
		int p = 0, q = 0;
		convertRational(num, p, q);

		cout << p << "/" << q << endl;
	}
};

