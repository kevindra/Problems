/*
 * ReverseLinkedList.cpp
 *
 *  Created on: 15-Feb-2013
 *      Author: Kevindra
 */

#include <iostream>

using namespace std;

class ReverseLinkedList {
private:
	struct node {
		int n;
		node * next;
	};
	node *createnewnode(int n) {
		node *np = new node;
		np->n = n;
		np->next = NULL;
		return np;
	}

	void insert(node *&head, int n) {
		if (head == NULL) {
			head = createnewnode(n);
			return;
		}
		node *np = createnewnode(n);
		np->next = head;
		head = np;
	}

	void display(node *head) {
		if (head == NULL)
			return;

		cout << head->n << ", ";
		display(head->next);
	}

	void printReverse(node *head) {
		if (head == NULL)
			return;

		printReverse(head->next);
		cout << head->n << ", ";
	}

	// reversing a linked list, [doesn't return the updated head]
	void reverse(node *&head, node *curr, node *prev) {
		if (curr == NULL)
			return;

		// change the head to the end of the linked list
		if (curr->next == NULL)
			head = curr;

		node *next = curr->next;
		curr->next = prev;
		reverse(head, next, curr);
	}

public:
	void run() {
		int a[] = { 5, 4, 3, 2, 1 }, n = 5;
		node *head = NULL;
		for (int i = 0; i < n; i++)
			insert(head, a[i]);

		cout << "LL: ";
		display(head);
		cout << endl;

		cout << "Print reverse: ";
		printReverse(head);
		cout << endl;

		node *prev = NULL;
		reverse(head, head, prev);

		cout << "LL after reversing: ";
		display(head);
		cout << endl;

	}
};
