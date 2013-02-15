/*
 * CharactersSubstitution.cpp
 *
 * http://www.careercup.com/question?id=15419952
 *
 * Given a hashmap M which is a mapping of characters to arrays of substitute characters,
 * and an input string S, return an array of all possible mutations of S (where any
 * character in S can be substituted with one of its substitutes in M, if it exists).
 *
 * What is the time complexity? What is the space complexity? Can you optimize either?
 *
 * Example input:
 * M = { f: [F, 4], b: [B, 8] }
 * S = fab
 *
 * Expected output:
 *[fab, Fab, 4ab, faB, FaB, 4aB, fa8, Fa8, 4a8]
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class CharactersSubstitution {
private:
	vector<string> allSubs(map<char, vector<char> > g, string s, int i,
			string output) {
		vector<string> res;
		if (i == s.size()) {
			res.push_back(output);
			return res;
		}

		vector<char> v = g[s[i]];
		vector<string> v1 = allSubs(g, s, i + 1, output + s[i]);

		vector<string> v2;
		for (int j = 0; j < v.size(); j++) {
			vector<string> v3 = allSubs(g, s, i + 1, output + v[j]);
			v2.insert(v2.end(), v3.begin(), v3.end());
		}
		res.insert(res.end(), v1.begin(), v1.end());
		res.insert(res.end(), v2.begin(), v2.end());
		return res;
	}
public:
	void run() {
		map<char, vector<char> > g;

		vector<char> v;
		v.push_back('F');
		v.push_back('4');
		g['f'] = v;

		v.clear();
		v.push_back('B');
		v.push_back('8');
		g['b'] = v;

		vector<string> res = allSubs(g, "fab", 0, "");

		for (int i = 0; i < res.size(); i++)
			cout << res[i] << ", ";
	}
};

