/*
 * Permutation.cpp
 *
 *  Created on: 10-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Permuter {
public:
	void permuteWithoutRepition(string s, unsigned int i) {
		if (i == 0)
			sort(s.begin(), s.end());

		if (i == s.size() - 1)
			cout << s << endl;
		else {
			for (unsigned int j = i; j < s.size(); j++) {
				swap(s[i], s[j]);
				permuteWithoutRepition(s, i + 1);
				swap(s[i], s[j]);
			}
		}

	}
	//AAB = AAB, ABA, BAA
	void permuteWithRepitition(string s, unsigned int i) {
		if (i == 0)
			sort(s.begin(), s.end());

		if (i == s.size() - 1)
			cout << s << endl;
		else {
			int bitmap = 0;
			for (unsigned int j = i; j < s.size(); j++) {
				if ((bitmap & (s[j] - 'a' + 1)) > 0)
					continue;

				swap(s[i], s[j]);
				permuteWithRepitition(s, i + 1);
				swap(s[i], s[j]);
				bitmap |= s[j] - 'a' + 1;
			}
		}
	}

	void run() {
		string s = "aabb";
		permuteWithRepitition(s, 0);
	}
};

