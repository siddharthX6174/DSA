#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s.size() > 10) {
			cout << s[0];
			cout << s.size() - 2;
			cout << s[s.size() - 1];
			cout << "\n";
		} else {
			cout << s << "\n";
		}
	}
	return 0;
}