#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


vector<int> divisors;

void fun(int n) {

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);

			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}

	// sort them
	sort(divisors.begin(), divisors.end());

	return;
}

int main() {
	fast();

	int t;
	cin >> t;
	while (t--) {
		divisors.clear();
		int n;
		cin >> n;
		fun(n);
		cout << divisors.size() << "\n";
	}

	return 0;
}