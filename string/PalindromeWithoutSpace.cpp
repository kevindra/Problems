/*
 * PalindromeWithoutSpace.cpp
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * http://leetcode.com/2012/01/palindrome-number.html
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

bool isPalin(int x, int &y) {
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	if (isPalin(x / 10, y) && (x % 10 == y % 10)) {
		y /= 10;
		return true;
	} else {
		return false;
	}
}
//int main() {
//	int num = 12221;
//	cout << "Is palin: " << isPalin(num, num) << endl;
//	return 0;
//}

