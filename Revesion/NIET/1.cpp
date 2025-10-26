# include <iostream>
using namespace std;
const int N = 10e7 + 1;

int main() {
	int a{}; // slot innput
	int sum{}; // finding sum of slot of non negative
	int count{};

	while (cin >> a) {
		if (a > 0) {
			sum += a % N;
		}

		count++;
		count % N;
	}

	int natural_sum = (count * (count + 1) / 2) % N;
	int ans = (natural_sum - sum) % N;
	cout << ans;

	return 0;
}