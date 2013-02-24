/*
 * LongestCommonSubstring.cpp
 *
 *  Created on: 17-Feb-2013
 *      Author: Kevindra
 */

/**
 * Given two string s1, s2. Find out the length of their longest common substring
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class LongestCommonSubstring {
private:
	string getLCS(int **m, int i, int j, string s1, string s2) {
		if (i == 0 || j == 0)
			return "";
		if (s1[i - 1] == s2[j - 1])
			return getLCS(m, i - 1, j - 1, s1, s2) + s1[i - 1];
		else if (m[i - 1][j] < m[i][j - 1])
			return getLCS(m, i, j - 1, s1, s2);
		else
			return getLCS(m, i - 1, j, s1, s2);
	}

	int **getLCSMatrix(string s1, string s2) {
		int r = s1.size() + 1, c = s2.size() + 1;
		int **m = (int**) malloc(r * sizeof(int *));
		for (int i = 0; i < c; i++)
			m[i] = (int *) malloc(c * sizeof(int));

		for (int i = 0; i < r; i++)
			m[i][0] = 0;

		for (int i = 0; i < c; i++)
			m[0][i] = 0;

		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					m[i][j] = m[i - 1][j - 1] + 1;
				} else {
					m[i][j] = max(m[i - 1][j], m[i][j - 1]);
				}
			}
		}
		print(m, r, c);
		return m;
	}

	void print(int **m, int r, int c) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	}

	set<string> getAllLCS(int **m, int i, int j, string s1, string s2,
			string s) {
		set<string> v;
		if (i == 0 || j == 0) {
			v.insert(s);
			return v;
		}

		if (s1[i - 1] == s2[j - 1]) {
			set<string> v1 = getAllLCS(m, i - 1, j - 1, s1, s2, s1[i - 1] + s);
			v.insert(v1.begin(), v1.end());
		} else if (m[i - 1][j] == m[i][j - 1]) {
			set<string> v1 = getAllLCS(m, i - 1, j, s1, s2, s);
			set<string> v2 = getAllLCS(m, i, j - 1, s1, s2, s);
			v.insert(v1.begin(), v1.end());
			v.insert(v2.begin(), v2.end());
		} else if (m[i - 1][j] < m[i][j - 1]) {
			set<string> v1 = getAllLCS(m, i, j - 1, s1, s2, s);
			v.insert(v1.begin(), v1.end());
		} else {
			set<string> v1 = getAllLCS(m, i - 1, j, s1, s2, s);
			v.insert(v1.begin(), v1.end());
		}
		return v;
	}

public:
	void run() {
		string s1 = "ABGIT";
		string s2 = "GITDCD";

		int **m = getLCSMatrix(s1, s2);

		cout<<"S1: "<<s1<<endl;
		cout<<"S2: "<<s2<<endl;
		cout << "LCS: " << getLCS(m, s1.size(), s2.size(), s1, s2) << endl;

		set<string> v = getAllLCS(m, s1.size(), s2.size(), s1, s2, "");

		cout << "All LCS: \n";
		set<string>::iterator it = v.begin();
		for (; it != v.end(); it++)
			cout << (*it) << endl;
	}
}
;

