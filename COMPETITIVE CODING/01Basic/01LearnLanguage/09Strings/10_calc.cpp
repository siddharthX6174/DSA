#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	// ooperator = op
	char op{};
	int opidx{};

	for (int i = 0; i < n; i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
			op = s[i];
			opidx = i;
			break;

		}
	}

	int a = stoi(s.substr(0, opidx));
	int b = stoi(s.substr(opidx + 1, n - opidx - 1));

	int ans{};

	if (op == '+') {
		ans = a + b;
	} else if (op == '-') {
		ans = a - b;
	} else if (op == '*') {
		ans = a * b;
	} else {
		ans = a / b;
	}

	cout << ans << endl;
	return 0;

}