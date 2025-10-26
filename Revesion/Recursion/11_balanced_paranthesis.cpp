# include <iostream>
using namespace std;

// print all the combination of the balanced paranthesis.

int n{};
char output[100];

// solve(0,0)

void solve(int i, int open_count, int close_count) {

	if (i == 2 * n) {

		output[i] = '\0';
		cout << output << endl;
		return;
	}


	// choosing closing bracket
	if (close_count < open_count) {
		output[i] = ')';
		solve(i + 1, open_count, close_count + 1);
	}

	// choosing openeing brackket
	if (open_count < n) {
		output[i] = '(';
		solve(i + 1, open_count + 1, close_count);
	}


}


int main() {
	cin >> n;

	solve(0, 0, 0); // i, open_coutn, closeCount
}


