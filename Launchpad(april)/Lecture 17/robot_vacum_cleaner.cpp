#include<iostream>

int Noise(std::string s) {
	int ans = 0;
	int cs = 0;

	for (int i{}; i < s.length(); i++) {
		if (s[i] == 's') {
			cs += 1;
		} else {
			ans += cs;
		}
	}

	return ans;
}

bool compare(std::string &x, std::string &y) {
	std::string xy = x + y;
	std::string yx = y + x;

	if (Noise(xy) > Noise(yx)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int n;
	std::cin >> n;

	std::string s[n];
	for (int i{}; i < n; i++) {
		std::cin >> s[i];
	}

	std::sort(s, s + n, compare);

	std::string final = "";

	for (int i = 0; i < n; i++) {
		final = final + s[i];
	}

	std::cout << Noise(final) << std::endl;

	return 0;

}