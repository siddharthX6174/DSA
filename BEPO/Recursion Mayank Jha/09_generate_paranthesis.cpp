#include<iostream>
using namespace std;
char output[100];
int n;

void solve(int i) {

	// base
	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	// choosing opening bracket
	output[i] = '(';
	solve(i + 1);

	// choosing closing bracket
	output[i] = ')';
	solve(i + 1);

}

int main() {
	cin >> n;
	solve(0);
}