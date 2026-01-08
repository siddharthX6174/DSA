#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<char> vowel {'A', 'E', 'I', 'O', 'U'};

	string s;
	cin >> s;

	int ans = INT_MIN;

	int prev = s.size(), last = s.size();

	// finding first ability
	int i;
	for (i = 0; i < s.size(); i++) {
		if (vowel.count(s[i])) {
			prev = i + 1;
			ans = prev;
			break;
		}
	}

	// finding last position of vowel
	for (int j = s.size() - 1; j >= i; j--) {
		if (vowel.count(s[j])) {
			last = j;
			break;
		}
	}

	int nw = prev;

	while (i < s.size()) {
		if (vowel.count(s[i])) {
			nw = i;
			if (i == last) {
				nw = i + 1;
			}
		}

		int ability = nw - prev;
		ans = max(ans, ability);
		prev = nw;
		i++;
	}

	cout << ans;

	return 0;

}