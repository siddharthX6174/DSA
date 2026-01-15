#include<bits/stdc++.h>
using namespace std;


// int main() {
// 	// divisor

// 	int n;
// 	cin >> n;

// 	// kon kon divide krskta hai
// 	for (int i = 1; i <= n; i++) {
// 		if (n % i == 0) {
// 			cout << i << " ";
// 		}
// 	}
// 	cout << endl;
// 	return 0;
// }

// -> root -> n

int main() {
	int n;
	cin >> n;

	int count = 0;
	int sum = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cout << i << " " << n / i << endl;
			count = count + 1;
			sum = sum + i;
			if (n / i != i) {
				count = count + 1;
				sum = sum + n / i;
			}
		}
	}

	cout << count << " " << sum << endl;
	return 0;
}