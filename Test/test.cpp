#include<iostream>


int main() {
	int n{};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cout << n - i << std::endl;
	}
	return 0;
}