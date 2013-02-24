/*
 * FlattenMultiLevelLL.cpp
 *
 *  Created on: 24-Feb-2013
 *      Author: Kevindra
 */

/**
 * ref:
 * http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/
 */

#include <iostream>

using namespace std;

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
//#define dbg(a) cout<<#a<<": "<<a<<endl;

class FlattenMultiLevelLL {
private:
	struct node {
		int n;
		node *next, *child;
	};

	node *createnewnode(int n) {
		node *np = new node;
		np->n = n;
		np->next = np->child = NULL;
		return np;
	}

	void flatten(node *head, node *tail) {
		if (head == tail)
			return;

		if (head->child) {
			tail->next = head->child;
			head->child = NULL;
			while (tail->next)
				tail = tail->next;
		}
		flatten(head->next, tail);
	}

	node *createList(int *a, int n) {
		node *head, *np;
		head = np = NULL;
		for (int i = 0; i < n; i++){
			if (head == NULL)
				head = np = createnewnode(a[i]);
			else {
				np->next = createnewnode(a[i]);
				np = np->next;
			}
		}
		return head;
	}

	void print(node *head) {
		if (head) {
			cout << head->n << " ";
			print(head->next);
		}
	}
public:
	void run() {
		int arr1[] = { 10, 5, 12, 7, 11 };
		int arr2[] = { 4, 20, 13 };
		int arr3[] = { 17, 6 };
		int arr4[] = { 9, 8 };
		int arr5[] = { 19, 15 };
		int arr6[] = { 2 };
		int arr7[] = { 16 };
		int arr8[] = { 3 };

		cout << SIZE(arr1) << endl;
		node *head1 = createList(arr1, SIZE(arr1));
		node *head2 = createList(arr2, SIZE(arr2));
		node *head3 = createList(arr3, SIZE(arr3));
		node *head4 = createList(arr4, SIZE(arr4));
		node *head5 = createList(arr5, SIZE(arr5));
		node *head6 = createList(arr6, SIZE(arr6));
		node *head7 = createList(arr7, SIZE(arr7));
		node *head8 = createList(arr8, SIZE(arr8));

		/* modify child pointers to create the list shown above */
		head1->child = head2;
		head1->next->next->next->child = head3;
		head3->child = head4;
		head4->child = head5;
		head2->next->child = head6;
		head2->next->next->child = head7;
		head7->child = head8;

		cout << "Linked List: " << endl;
		print(head1);
		cout << endl;

		node *tail = head1;
		while (tail->next)
			tail = tail->next;
		flatten(head1, tail);

		cout << "Linked List after flatten: " << endl;
		print(head1);
		cout << endl;
	}
};

