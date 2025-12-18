#include<iostream>
using namespace std;
char input[100];
char output[100];
int count = 0;


void solve(int i, int j) {

	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		count++;
		return;
	}

	//chosing the current charcter
	output[j] = input[i];
	solve(i + 1, j + 1);

	//not chosing the current charcter
	solve(i + 1, j);
}


int main() {
	cin >> input;
	solve(0, 0);

	cout << count ;
}