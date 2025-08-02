# include <iostream>

bool prime_check (int n) {
	bool ans = true;
	if (n <= 1) {
		ans = false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = false;
		}
	}
	return ans;
};

int main() {
	int num;
	std::cin >> num;

	for (int i = 1; i <= num; i++) {

		if (prime_check(i)) {
			std::cout << i << " is prime" << std::endl;
		}
	}

	return 0;

}