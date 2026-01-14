#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<char> vowel {'A', 'E', 'I', 'O', 'U', 'Y'};

	string s;
	cin >> s;

	int res = 0, index = -1;

	for (int i = 0; i < s.size(); i++) {
		if (vowel.count(s[i])) {
			res = max(res, i - index);
			index = i;
		}
	}

	res = max(res, (int)s.size() - index);
	cout << res << "\n";

	return 0;
}
