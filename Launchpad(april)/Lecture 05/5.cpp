#include<iostream>


int main() {
	char ch;
	int capitals = 0, small = 0, extra = 0;
	while (std::cin.get(ch)) {
		if (ch >= 65 && ch <= 90) {
			capitals += 1;
			ch = ch + 32;
			std::cout << ch;
		} else if ((ch >= 'a') && (ch <= 'z')) {
			small += 1;
			ch = ch - 32;
			std::cout << ch;
		} else {
			extra += 1;
			std::cout << ch;
		}
	}
	std::cout << std::endl << capitals  << " " << small << "  " << extra;

	return 0;
}