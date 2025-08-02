#include<iostream>
using namespace std;

string s, t:

int F(int i, int j) {

	if (i >= s.length() or j >= t.length()) {
		return 0;
	}

	if (s[i] == t[j]) {
		int op1 = 1 + F(i + 1, j + 1);
		return op1;
	} else {
		//s[i] != T[j]
		int op1 = F(i + 1, j);
		int op2 = F(i, j + 1);

		return max(op1, op2);
	}
}

int main() {

	cin >> s >> t;
	cout << F(0, 0) << endl;

}