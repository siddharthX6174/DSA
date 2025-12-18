#include<iostream>
using namespace std;
char output[100];
int n;

void solve(int i, int open_count, int close_count) {

	// base
	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	// choosing opening bracket
	if (open_count < n) {
		output[i] = '(';
		solve(i + 1, open_count + 1, close_count);
	}

	// choosing closing bracket
	if (close_count < open_count) {
		output[i] = ')';
		solve(i + 1, open_count, close_count + 1);
	}

}

int main() {
	cin >> n;
	solve(0, 0, 0); // iterator, open count, close count
}