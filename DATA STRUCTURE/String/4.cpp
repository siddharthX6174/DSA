# include <iostream>
# include <algorithm>

// calculate size witihtout using function
/*int main() {
	std::string s = "Siddharth";
	int start = 0;
	while (s[start] != '\0') {
		start ++;
	}

	std::cout << start;
	return 0;
}
*/

// reverse the string
// int main() {
// 	std::string s = "Shraddha.is.Moti>Moti.is.shraddha";
// 	int start = 0, end = s.size() - 1;
// 	while (start < end) {
// 		std::swap(s[start], s[end]);
// 		start++, end--;
// 	}

// 	std::cout << s;
// 	return 0;
// }


// check palindrome or not
int main() {
	std::string s = "NAMAN";
	bool ans = true;
	int start = 0, end = s.size() - 1;
	while (start < end) {
		if (s[start] != s[end]) {
			ans = false;
		}
		start++, end--;
	}

	std::cout << ans << std::endl;
	return 0;
}