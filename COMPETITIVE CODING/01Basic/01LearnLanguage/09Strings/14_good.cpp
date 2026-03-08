#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		bool found = false;

		for (int i = 0; i <= s.size() - 3; i++) {
			if ((s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') ||
			        (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0')) {
				cout << "Good\n";
				found = true;
				break;
			}
		}

		if (!found) cout << "Bad\n";
	}
}