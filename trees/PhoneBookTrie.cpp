/*
 * PhoneBookTrie.cpp
 * http://www.careercup.com/question?id=15423772
 *  Created on: 08-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>

using namespace std;

class PhoneBookTrie {
private:
	struct trie {
		int ph;
		trie *link[26];
	};

	trie *newnode(int ph) {
		trie *t = new trie;
		t->ph = ph;
		for (int i = 0; i < 26; i++)
			t->link[i] = NULL;
		return t;
	}

	void insert(trie *&root, string name, int i, int phone) {
		if (i == name.size() - 1) {
			if (root->link[name[i] - 'a'] == NULL)
				root->link[name[i] - 'a'] = newnode(phone);
			return;
		}

		if (root->link[name[i] - 'a'] == NULL)
			root->link[name[i] - 'a'] = newnode(-1);
		insert(root->link[name[i] - 'a'], name, i + 1, phone);
	}

	void find(trie *r, string s, int i, string t) {
		if (r == NULL) {
			return;
		}

		if (r->ph != -1) {
			cout << t << ": " << r->ph << endl;
			return;
		}

		if (i < s.size())
			find(r->link[s[i] - 'a'], s, i + 1, t + s[i]);
		else {
			for (int x = 0; x < 26; x++)
				find(r->link[x], s, i + 1, t + (char) ('a' + x));
		}
	}

	void print(trie *r) {
		if (r == NULL)
			return;

		cout << r->ph << " -> ";
		for (int i = 0; i < 26; i++)
			print(r->link[i]);
	}
public:
	void run() {
		string names[] = { "rihanna", "ricky", "peter", "ron" };
		int phones[] = { 11111, 22222, 33333, 44444 };
		int n = 4;

		trie *root = newnode(-1);

		for (int i = 0; i < n; i++) {
			insert(root, names[i], 0, phones[i]);
		}

		find(root, "r", 0, "");
	}
};
