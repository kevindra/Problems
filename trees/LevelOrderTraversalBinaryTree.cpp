/*
 * LevelOrderTraversalBinaryTree.cpp
 * http://leetcode.com/2010/09/printing-binary-tree-in-level-order.html
 *
 *  Created on: 02-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <list>
#include "../lib/BinaryTree.h"

using namespace std;

/**
 * level order traversal
 * using two queues
 */
void level_order_traversal_two_queues(bst *root) {
	list<bst*> first, second;

	first.push_back(root);
	while (!first.empty()) {
		bst *f = first.front();
		first.pop_front();

		if (f) {
			cout << f->val << " ";
			second.push_back(f->left);
			second.push_back(f->right);
		}
		if (first.empty()) {
			cout << endl;
			swap(first, second);
		}
	}
}

/**
 * using one queue and two counters (number of current level nodes and next level nodes)
 * The single queue solution requires two extra counting variables which keep tracks of
 * the number of nodes in the current level (nodesInCurrentLevel) and the next level (nodesInNextLevel).
 * When we pop a node off the queue, we decrement nodesInCurrentLevel by one.
 * When we push its child nodes to the queue, we increment nodesInNextLevel by two.
 * When nodesInCurrentLevel reaches 0, we know that the current level has ended, therefore we print
 * an endline here.
 */
void level_order_traversal_single_queue(bst *root) {
	list<bst *> q;
	q.push_back(root);

	int next_level_nodes = 0, current_level_nodes = 1;
	while (!q.empty()) {
		bst *n = q.front();
		q.pop_front();

		current_level_nodes -= 1;
		if (n) {
			cout << n->val << " ";
			q.push_back(n->left);
			q.push_back(n->right);
			next_level_nodes += 2;
		}
		if (current_level_nodes == 0) {
			cout << endl;
			current_level_nodes = next_level_nodes;
			next_level_nodes = 0;
		}
	}
}

//int main() {
//	int a[] = { 9, 7, 3, 20, 15 }, n = 5;
//
//	cout << "Hello";
//	BST *bst = new BST;
//	for (int i = 0; i < n; i++)
//		bst->insert_in_bst(a[i]);
//
//	cout << "Inorder : \n ";
//	bst->inorder();
//
//	cout << " Level order: \n ";
//	level_order_traversal_two_queues(bst->get_root());
//
//	cout << " Level order 2: \n ";
//	level_order_traversal_single_queue(bst->get_root());
//
//	return 0;
//}

