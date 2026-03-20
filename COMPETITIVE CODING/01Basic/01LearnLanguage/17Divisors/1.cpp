#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main() {
	fast();

	string s;
	cin >> s;

	int n = s.size();

	vector<int> pref(n);
	pref[0] = (s[0] == 'a');

	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + (s[i] == 'a');
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;

		l-- ; r--;

		int ans = pref[r] - (l > 0 ? pref[l - 1] : 0);

		cout << ans << "\n";
	}

	return 0;
}