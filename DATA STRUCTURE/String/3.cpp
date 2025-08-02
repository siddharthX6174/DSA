# include <iostream>

int main() {
	std::string s{};
	getline(std::cin, s);
	std::cout << s << std::endl;


	// +
	std::string s1 = "rohit" , s2 = "mohit";
	std::string s3 = s1 + s2;
	std::cout << s3;
	return 0;
}