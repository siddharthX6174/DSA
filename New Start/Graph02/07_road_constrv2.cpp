#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	bool forbidden[1001] = {false};

	// Mark all cities that appear in forbidden pairs
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		forbidden[a] = true;
		forbidden[b] = true;
	}

	// Find a city not in any forbidden pair (this will be our hub)
	int hub = 1;
	while (forbidden[hub]) {
		hub++;
	}

	// Output: n-1 roads, all connecting to the hub
	cout << n - 1 << endl;

	// Connect all cities to the hub
	for (int i = 1; i <= n; i++) {
		if (i != hub) {
			cout << hub << " " << i << endl;
		}
	}

	return 0;
}