# include <iostream>
# include <cmath>

int digit_count (int n);
int sum_for_arm (int n, int power);
bool armstrong (int n, int sum_of_its_digits);

int main() {
	int n{};
	std::cin >> n;

	int power = digit_count(n);
	int sum_of_digits = sum_for_arm(n, power);
	bool arm_check = armstrong (n, sum_of_digits);

	if (arm_check) {std::cout << "true" << std::endl;}
	else {std::cout << "false" << std::endl;}

	return 0;
}

int digit_count (int n) {
	int count{};
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int sum_for_arm (int n, int power) {
	int sum {};
	while (n != 0) {
		int digit = n % 10;
		sum += std::pow(digit, power);
		n /= 10;
	}
	return sum;
}

bool armstrong (int n, int sum_of_its_digits) {
	bool ans{true};
	if (n != sum_of_its_digits) {
		ans = false;
	}

	return ans;
}

