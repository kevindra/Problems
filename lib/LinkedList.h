/*
 * LinkedList.h
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

struct llist {
	int n;
	llist *next;
};

llist *new_llist_node(int x) {
	llist *np = new llist;
	np->n = x;
	np->next = NULL;
	return np;
}

void display_llist(llist *head) {
	if (head == NULL)
		return;
	cout << head->n << ", ";
	display_llist(head->next);
}
void insert_in_llist(llist *&n, int x) {
	if (n == NULL) {
		n = new_llist_node(x);
		return;
	}
	llist *np = new_llist_node(x);
	np->next = n;
	n = np;
}

#endif /* LINKEDLIST_H_ */
