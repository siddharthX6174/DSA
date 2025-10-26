# include <iostream>
using namespace std;

// print all the combination of the brackets.

int n{};
char output[100];

// solve(0,0)

void solve(int i) {

	if (i == 2 * n) {

		output[i] = '\0';
		cout << output << endl;
		return;
	}

	// choosing openeing brackket
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



// leana hai
// i->i+1 & j->j+1

// nhi lena hai
// i->i+1 & j->j