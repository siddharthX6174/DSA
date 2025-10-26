# include <iostream>
using namespace std;

char input[100];
char output[100];
int count{};

// solve(0,0)

void solve(int i, int j) {

	if (input[i] == '\0') {

		output[j] = '\0';
		count++;
		cout << output << endl;
		return;
	}

	// choosing the current character
	output[j] = input[i];
	solve(i + 1, j + 1);

	// not choosing the current charactter
	solve(i + 1, j);
}


int main() {
	cin >> input;

	solve(0, 0);

	cout << count << endl;
}



// leana hai
// i->i+1 & j->j+1

// nhi lena hai
// i->i+1 & j->j