#include<iostream>
using  namespace std;


//~ (n+q)

int main() {
	int n;
	cin >> n;

	int a[n] {0};
	int x;

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//Precompute : Build the Prefix Array/Running Sum
	int pre[11] {0};

	pre[0] = a[0];
	for (int i = 1; i < n; i += 1) {
		pre[i] = pre[i - 1] + a[i];
	}

	int q;
	cin >> q;

	int l, r;

	while (q > 0) {
		cin >> l >> r;
		int sum = 0;

		if (l == 0) {
			sum = pre[r];
		} else {
			sum = pre[r] - pre[l - 1];
		}

		cout << sum << endl;

		q -= 1;
	}
}