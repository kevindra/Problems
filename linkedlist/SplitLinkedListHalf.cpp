/*
 * http://leetcode.com/2010/09/splitting-linked-list.html
 */
#include <iostream>
#include "../lib/LinkedList.h"

using namespace std;

void split(llist *head) {
	llist *t1 = head;
	llist *mid = head;
	while (t1 && t1->next && t1->next->next) {
		mid = mid->next;
		t1 = t1->next->next;
	}

	llist *secondHalf = mid->next;
	mid->next = NULL;
	llist *firstHalf = head;

	cout<<"First half: ";
	display_llist(firstHalf);

	cout<<"Second half: ";
	display_llist(secondHalf);
}

//int main() {
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	int n = 6;
//
//	llist *head = NULL;
//	for (int i = 0; i < n; i++)
//		insert(head, a[i]);
//
//	cout << "Linked List: ";
//	display_llist(head);
//
//	split(head);
//	return 0;
//}
