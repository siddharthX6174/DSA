# include <iostream>
// store honeymoney

int main() {
	char arr[10] {};
	for (int i = 0; i < 10; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i];
	}

	std::cout << std::endl;
	std::cout << arr << std::endl;

	// variable size string
	char arr_1[20] {};
	std::cin >> arr_1;
	arr_1[2] = '\0';
	std::cout << arr_1;
	return 0;
}