#include<bits/stdc++.h>
using namespace std;

// int main() {
// 	int n;
// 	cin >> n;

// 	bool isPrime = true;
// 	for (int i = 2; i < n; i++) {
// 		if (n % i == 0) {
// 			isPrime = false;
// 			break;
// 		}
// 	}

// 	cout << isPrime << endl;
// 	return 0;
// }

// O (sqrt(n))
int main() {
	int n;
	cin >> n;

	bool isPrime = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		cout << "Yes prime\n";
	} else {
		cout << "No nahi hai prime\n";
	}
	return 0;
}