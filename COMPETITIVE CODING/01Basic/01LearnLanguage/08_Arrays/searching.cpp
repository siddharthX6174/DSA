#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int k;
	cin >> k;

	int ans{ -1};
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}