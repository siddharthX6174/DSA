// #include<iostream>
// #include<cstring>
// using namespace std;

// int main() {
// 	int n{}, m{};
// 	cin >> n >> m;

// 	int A[n + 1] {};
// 	//memset(A, -1, sizeof(A));

// 	for (int i = 0; i < n; i++) {
// 		cin >> A[i];
// 	}

// 	int maxi = INT_MIN;
// 	for (int i = 0; i < m; i++) {
// 		maxi = max(A[i], maxi);
// 	}

// 	int freq[maxi + 1];
// 	memset(freq, -1, sizeof(freq));

// 	for (int i = 0; i < m; i++) {
// 		freq[A[i]] = 0;
// 	}

// 	for (int i = 0; i < n; i++) {
// 		int x = A[i];
// 		if (freq[x] >= 0) {
// 			freq[x]++;
// 		}
// 	}

// 	for (int i = 0; i <= m; i++) {
// 		int x = freq[i];
// 		if (x > 0) {
// 			cout << x << "\n";
// 		}
// 	}

// 	return 0;

// }

#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int freq[100001] = {0};

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		freq[x]++;
	}

	for (int i = 1; i <= m; i++) {
		cout << freq[i] << "\n";
	}
}