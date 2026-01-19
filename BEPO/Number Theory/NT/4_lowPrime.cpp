#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
// Seive Algo
vector<bool> isPrime(N, 1);
vector<int> lowPrime(N, 0), highPrime(N, 0);

int main() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; i++) {
		if (isPrime[i] == true) {
			lowPrime[i] = highPrime[i] = i;
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
				highPrime[j] = i;
				if (lowPrime[j] == 0) {
					lowPrime[j] = i;
				}
			}
		}
	}

	int num;
	cin >> num;

	vector<int> Prime_factors;
	// store in terms is 2^3

	unordered_map<int, int> PF;

	while (num > 1) {
		int primefactor = lowPrime[num];
		while (num % primefactor == 0) {
			num /= primefactor;
			Prime_factors.push_back(primefactor);
			PF[primefactor]++;
		}
	}

	for (auto factor : Prime_factors) {
		cout << factor << " ";
	}
	cout << endl;
	for (auto x : PF) {
		cout << x.first << " " << x.second << endl;
	}
	// for (int i = 1; i < 100; i++) {
	// 	cout << i << "  l: " << lowPrime[i] << "    " << "  h: " << highPrime[i] << endl;
	// }
	return 0;
}