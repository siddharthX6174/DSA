# include <iostream>

int main () {
	/*Loop:
	1. start
	2. End
	3. Task
	4. Next Stage*/

	int count = 1; // start of the loop

	while (count <= 10) {
		std::cout << count << " "; //Task
		count += 1; // Next stage
	}
}