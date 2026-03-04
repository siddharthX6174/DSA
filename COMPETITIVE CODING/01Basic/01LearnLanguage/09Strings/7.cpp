#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int sum = 0;
	for (char& x : s) {
		sum += x - '0';
	}
	cout << sum;
	return 0;
}