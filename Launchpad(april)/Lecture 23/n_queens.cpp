# include <iostream>
int n {};
char board[100][100];
bool CanPlace(int r, int c) {
	// check in the current rowq:
	for (int i{}; i < c; i++) {
		if (board[r][i] == 'Q') {
			return false;
		}
	}
	// check in current column:
	for (int i{}; i < c; i++) {
		if (board[i][c] == 'Q') {
			return false;
		}
	}

	// left diagonal
	int i = r , j = c;

	while (i >= 0 and j >= 0) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--, j--;
	}


	//right diagonal
	i = r , j = c;
	while (i >= 0 and j < n ) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--, j++;
	}

	return true;

}

bool F(int r) {
	if (r == n) {
		// YOu have filled for 0 to n-1 row that means
		// you have found a answer print it.

		for (int i{}; i < n; i++) {
			for (int j{}; j < n; j++) {
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;


		// I will always return false form here since I want ot print all the paths.
		// print all the paths.
		// i.e I want recusion to still try to find another
		// path even throuobj it has found one.
		return false;
	}

	// currently you are at rth row.
	for (int c = 0; c < n; c++) {
		// I will try to to pput queene here and ask recursion will i be able to solve for the rest.
		// check if you can put queen at r,c co-cordinate or not?

		if (CanPlace(r, c) == 1 ) {
			// you can put queen here.

			board[r][c] = 'Q';
			bool small_ans = F(r + 1);

			if (small_ans = 1) {
				return true;
			}

			// if you are here // that means yha par quee rakh kr ya to solutuion tumne print karwadiya hai
			// ya fir solution yaha par queen rakh kar exist nhi krta .
			// dono situtation me board[r][c] ko vapas se  "." bana do.
			board[r][c] = '.'; // backtrackjingo
		}

	}

	// if i am standing here thet means for my current row r
	// i was not able to put qyueen on any column c.
	// hence I return false.
	return false;
}


int main() {
	//int n{};
	std::cin >> n;

	//char board[100][100];
	// Initially evey box is a .(dot)

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			board[i][j] = '.';
		}
	}

	// F(0) : It returns true/ false representing if i am able to put n qyeens or not.
	int ans = F(0);
	std::cout << ans << std::endl;
}