// A person wants to go from origin to a particular location, he can move in onluy 4 directions (i.e.
// East , West , North, South) but his friend gave him a long route , help a person to find
// minimum Moves so that he can reach to the destination.

// Input 1 = NESNWES
// Output 1 - E

// You need to print the lexicographically (disc order) sorted string. Assume the string will
// have onely 'E' 'N' 'S' 'W' characters.

#include<iostream>


int main() {
	char ch;
	int x{} , y{};
	while (std::cin >> ch) {

		if (ch == 'N') {
			y += 1;
		}	else if (ch == 'S') {
			y -= 1;
		} else if (ch == 'E') {
			x += 1;
		} else {
			x -= 1;
		}
	}

	std::cout << x << " " << y << " " << std::endl;

	if (x > 0) {
		// Iwill have to print R first and the other direction.
		// Print Magnitude time fo x --> E.
		// according to value of y print either
		// N or S.

		int i = 1;
		while (i <= x) {
			std::cout << 'E';
			i += 1;
		}

		if (y > 0) {
			// I have to Print N.
			int j = 1;
			while (j <= y) {
				std::cout << 'N';
				j += 1;
			}
		}
	} else {
		// I will have to print the other direction first and then W.
		// According to value of y print N or S.
		// Print the magnitude time of x --> W.
	}
}