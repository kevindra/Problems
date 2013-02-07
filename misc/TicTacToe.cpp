/*
 * TicTacToe.cpp
 * Design an algorithm to figure out is someone has won in a game of tic-tac-toe.
 *  Created on: 07-Feb-2013
 *      Author: Kevindra
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#define CROSS 0
#define CIRCLE 1
#define BLANK 2

enum DIR {
	LEFT,
	RIGHT,
	DOWN,
	UP,
	DIAGONALLY_DOWN_RIGHT,
	DIAGONALLY_UP_LEFT,
	DIAGONALLY_UP_RIGHT,
	DIAGONALY_DOWN_LEFT,
};

int di[] = { 0, 1, 1, -1 };
int dj[] = { 1, 0, 1, 1 };

bool isValid(int i, int j, int row, int col) {
	if (i >= 0 && i < row && j >= 0 && j < row) {
		return true;
	}
	return false;
}

bool go(int **a, int i, int j, int dir, int depth, int row, int col) {
	if (a[i][j] == BLANK)
		return false;

	int inew = i + di[dir];
	int jnew = j + dj[dir];

	if (!isValid(inew, jnew, row, col))
		return (depth == row - 1);

	if (a[inew][jnew] == a[i][j]) {
		cout << "here";
		return go(a, inew, jnew, dir, depth + 1, row, col);
	}
	return false;
}
bool hasWon(int **a, int row, int col) {
	bool won = false;
	for (int d = 0; d < 4; d++) {
		for (int x = 0; x < col; x++) {
			int inew = di[d];
			int jnew = x + dj[d];
			if (isValid(inew, jnew, row, col)) {
				cout << "[0," << x << "]  -> [" << inew << "," << jnew
						<< "] \n";
				won |= go(a, 0, x, d, 0, row, col);
			}
		}
		for (int x = 1; x < row; x++) {
			int inew = x + di[d];
			int jnew = dj[d];

			if (isValid(inew, jnew, row, col)) {
				cout << "[" << x << ",0]  -> [" << inew << "," << jnew
						<< "] \n";
				won |= go(a, x, 0, d, 0, row, col);
			}
		}
		cout << "------------------------------------\n";
	}
	return won;
}

//int main() {
//	int row = 3, col = 3;
//	int **a = (int**) malloc(row * sizeof(int));
//	for (int i = 0; i < row; i++)
//		a[i] = (int*) malloc(col * sizeof(int));
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			a[i][j] = BLANK;
//			a[2][0] = a[2][1] = a[2][2] = CROSS;
//			a[1][1] = CIRCLE;
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
//
//	cout << "Has Won: " << hasWon(a, row, col) << endl;
//	return 0;
//}

