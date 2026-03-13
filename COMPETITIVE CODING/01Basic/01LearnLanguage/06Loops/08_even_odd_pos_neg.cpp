#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pos{}, neg{}, even{}, odd{};

	while (n--) {
		int x;
		cin >> x;
		if (x > 0) {
			pos++;
		}
		if (x < 0) neg++;
		if (x % 2 == 0) even++;
		else odd++;
	}

	cout << "Even: " << even << "\n";
	cout << "Odd: " << odd << "\n";
	cout << "Positive: " << pos << "\n";
	cout << "Negative: " << neg << "\n";

	return 0;
}