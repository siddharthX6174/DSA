#include<iostream>
char ch[100];

void F(int i) {

	if (ch[i] == '\0') {
		std::cout << ch << std::endl;
		return;


	}
	for (int j = i; ch[j] != '\0'; j++) {
		std::swap(ch[i], ch[j]);
		F(i + 1);
		std::swap(ch[i], ch[j]);

	}
}


int main() {
	std::cin >> ch;
	F(0);
}