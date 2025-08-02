#include<iostream>


int main() {

	char ch;
	// while (std::cin >> ch) {
	// 	std::cout << ch;
	// }

	while (std::cin.get(ch)) {
		std::cout << ch;
	}
}


// cin can't read white spacees
// std::cin.get() reads the  1 character at a time so it can read white charter