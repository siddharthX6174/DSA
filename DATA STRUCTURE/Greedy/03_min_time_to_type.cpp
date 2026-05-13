#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int minTimeToType(string word) {
	int ans = word.size();
	char point = 'a';
	for (auto& ch : word) {
		ans += min(abs(ch - point), 26 - abs(ch - point));
		point = ch;
	}
	return ans;
}

int main() {
	fast();

	string word;
	cin >> word;

	cout << minTimeToType(word) << "\n";


	return 0;
}