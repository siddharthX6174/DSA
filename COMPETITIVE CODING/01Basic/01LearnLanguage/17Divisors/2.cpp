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


	int a , b, c;
	cin >> a >> b >> c;


	fun(c);

	int cnt = 0;

	int i = 0;
	for (i ; i < divisors.size(); i++) {
		if (divisors[i] >= a) {
			break;
		}
	}

	for (i; i < divisors.size() and divisors[i] <= b; i++) {
		cnt++;
	}


	cout << cnt << endl;
	return 0;
}