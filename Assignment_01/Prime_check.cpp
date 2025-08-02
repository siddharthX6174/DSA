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

	bool is_prime = prime_check(num);

	if (is_prime) {
		std::cout << num << " is prime" << std::endl;
	} else {
		std::cout << num << " is not prime" << std::endl;
	}

	return 0;

}