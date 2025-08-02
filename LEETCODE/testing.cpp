# include <iostream>


int main() {
	std::string s = "the sky is blue";
	std::cout << s.size() << std::endl;;
	int st = s.size() - 1, en = s.size() - 1;
	while (s[st] != '\0') {
		st--;
	}
	std::cout << st << std::endl;
}