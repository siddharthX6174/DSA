#include<iostream>
using namespace std;
char board[10][10];


bool CanPlace(int x, int y, char ch) {

	// check 1 ; we are checking the current row.

	for (int i{}; i < 9; i++) {
		if (board[x][i] == ch) {
			return false;
		}
	}


	// chech 2 : we are checking the current colun/
	for (int i{}; i < 9; i++) {
		if (board[i][y] == ch) {
			return false;
		}
	}

	// check 3 : check the submatrix....
	int sx = (y / 3) * 3;
	int sy = (y / 3) * 3;

	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; i < sy + 3; j++) {
			if (board[i][j] == ch) {
				return false;
			}
		}
	}

	return true;
}

bool F(int x, int y) {

	if (x == 9) return true;
	if (y == 9) return F(x + 1, 0);

	// current state is F(x,y).

	if (board[x][y] != '.') {
		return F(x, y + 1);
	} else {
		for (char ch = '1'; ch <= '9'; ch++) {
			if (CanPlace(x, y, ch) == 1) {

				board[x][y] = ch;

				bool small_ans = F(x, y + 1);

				if (small_ans == 1) {
					return true;
				}
			}

		}
		// if u are standiing here that means you have not yet return true,
		// from x,y box,
		// yuo are not able to put any number in the current bnox x,y.


	}

	board[x][y] = '.';  // Backtracking
	return false;
}


int main() {
	for (int i{}; i < 9; i++) {
		for (int i{}; i < 9; i++) {
			cin >> board[i][j];
		}
	}

	bool ans = F(0, 0);
	if (ans == 0) {
		cout << "-1" << endl;
		return 0;
	}

	for (int i{}; i < 9; i++) {
		for (int j{}; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}