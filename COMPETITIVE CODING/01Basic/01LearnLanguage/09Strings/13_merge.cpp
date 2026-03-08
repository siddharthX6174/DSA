#include<iostream>
#include<string>
using namespace std;

int main() {
	int t{};
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		int n1 = s1.size() , n2 = s2.size();

		string result = "";

		int i = 0;
		while (i < n1 and i < n2) {
			result += s1[i];
			result += s2[i];
			i++;
		}

		// check who is big one
		if (n1 > n2) {
			result += s1.substr(i, n1 - i);
		} else {
			result += s2.substr(i, n2 - i);
		}

		cout << result << "\n";
	}
	return 0;
}