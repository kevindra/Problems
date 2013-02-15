/*
 * CodingSystem.cpp
 *
 *  Created on: 12-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <string>
#include <vector>

/**
 * We have a coding system from alphabets to numbers where a=1, b=2, ...z=26.
 * You are given a string of digits as an input. Write a function that will
 * compute the number of valid interpretations of the input.
 *
 * Here are some examples:
 * f('11') = 2 Actual interpretations: ('aa', 'k')
 * f('111') = 3 Actual interpretations: ('aaa', 'ak', 'ka')
 * http://www.careercup.com/question?id=15430817
 */
using namespace std;

class CodingSystem {
private:
	char getStr(int v) {
		return v - 1 + 'a';
	}

	vector<string> getInterpretations(string given, unsigned int i, string s) {
		vector<string> v1;
		if (i > given.size() - 1) {
			v1.push_back(s);
			return v1;
		}

		if (given[i] == '1' && i + 1 < given.size()) {
			v1 = getInterpretations(given, i + 2,
					s + getStr((given[i] - '0') * 10 + (given[i + 1] - '0')));
		}

		vector<string> v2 = getInterpretations(given, i + 1,
				s + getStr(given[i] - '0'));
		v1.insert(v1.end(), v2.begin(), v2.end());
		return v1;
	}

	int getCount(string s, unsigned int i) {
		if (i > s.size())
			return 1;

		if (s[i] == '1' && i + 1 < s.size()) {
			return getCount(s, i + 2) + getCount(s, i + 1);
		}
		return getCount(s, i + 1);
	}

	int getCountNonRecursive(string s) {
		int *c = new int[s.size()];

		for (int i = 0; i < s.size(); i++)
			c[i] = 1;
		c[0] = 1;

		for (int i = 2; i < s.size(); i++)
			if (s[i - 2] == '1')
				c[i] += c[i - 2] + c[i - 1];
			else
				c[i] += c[i - 1];
		return c[s.size() - 1];
	}
public:
	void run() {
		string s = "11111";
		vector<string> res = getInterpretations(s, 0, "");

		cout << "Size: " << res.size() << endl;

		cout << "Interpretations: \n";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}

		cout << "Count: " << getCount(s, 0) << endl;
		cout << "Count: " << getCountNonRecursive(s) << endl;
	}
};

