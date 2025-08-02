# include <iostream>

int main() {
	int a{}, b{};
	std::cin >> a >> b;

	for (int i{1}; ; i++) {
		if ((i % a == 0) and (i % b == 0)) {
			std::cout << i ;
			break;
		}
	}

	return 0;
}