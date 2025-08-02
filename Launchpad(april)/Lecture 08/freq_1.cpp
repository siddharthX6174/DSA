#include<iostream>
using namespace std;

int main() {
	int n{};
	std::cin >> n;

	int a[n] {};
	int x;

	for (int i{}; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int currenct_elelment = a[i];
		int count = 0;

		if (currenct_elelment != INT_MIN) {
			for (int j = 0; j < n; j++) {
				// er are tyring to find the c

				if (a[j] == currenct_elelment) {
					count++;
					a[j] = INT_MIN;
				}
			}

			cout << currenct_elelment << ": " << count << endl;

		}

	}


	return 0;

}

