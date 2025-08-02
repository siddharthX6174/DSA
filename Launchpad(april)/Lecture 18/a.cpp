#include <iostream>
#include <climits>

const int SIZE = 1e7 + 1;
long long* diff ;


int main() {
	int n{};
	std::cin >> n;


	int max_b = 0; // To limit loop rane
	diff = new long long[SIZE] {};

	while (n--) {
		int a{}, b{};
		std::cin >> a >> b;

		diff[a] += 1;
		if (b + 1 < SIZE) {
			diff[b + 1] -= 1;
		}
		if (b > max_b) max_b = b;
	}

	long long curr = 0;
	long long maxi = 0;
	for (int i = 0; i <= max_b; ++i) {
		curr += diff[i];
		maxi = std::max(curr, maxi);
	}


	std::cout << maxi ;

	delete[] diff;
	return 0;
}
