#include<bits/stdc++.h>
using namespace std;
/*
	solve(0) : For every i check if i can place queen here or not if 	+   solve(1)
				yes than place queen and ask recursion

	Big Probelem : ky m 0 se lekar n-1 row tak queen rakh paarha hun..
*/

/*
	I am taking a board as an input where every box is a '.' char . and whenever i will place queen
	i will put 'Q'
*/

bool CanPlace(char board[][100], int row, int col, int n) {

	// current row mai koi queen nahi honi chiyue
	for (int i = 0; i < n; i++) {
		if (board[row][i] == 'Q') return false;
	}

	// current col mai koi queen nhi honi chiye
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q') return false;
	}

	// top left diagonal
	int i = row, j = col;
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--;
		j--;
	}

	// top right diagonal
	int i = row, j = col;
	while (i >= 0 and j < n) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--;
		j++;
	}

	return true;
}

// int couunt = 0;
bool solve(char board[][100], int row, int n) {

	// base
	if (row == n) {
		// print the board
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] <<  " ";
			}
			cout << '\n';
		}

		// count ++;

		return true;
		// return false; if false print all the ways
	}

	for (int col = 0; col < n; col++) {
		// This current col is a potential place to put queen, can i put queen here
		// here i have to check

		if (CanPlace(board, row, col, n) == 1) {
			board[row][col] = 'Q';

			bool smallproblem = solve(board, row + 1, n);

			if (smallproblem == 1) {
				return true;
			}

			// That means jo yeh current column hai jo potential queen placed tha isse answer nhi
			// mila and hence wapas se dot bna dunge .. mtlb backtrack

			board[row][col] = '.'; // kind of small bbacktrack
		}
	}

	// backtrack for this board configuration
	return false;
}