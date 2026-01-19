#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> divisors[N];
int Sum[N];

int main() {
	// Precompute divisors
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
			Sum[j] += i;
		}
	}

	// Print divisors for numbers 1 to 9
	for (int i = 1; i < 10; i++) {
		cout << "Divisors of " << i << ": ";
		for (int div : divisors[i]) {
			cout << div << " ";
		}
		cout << endl;
	}

	return 0;
}