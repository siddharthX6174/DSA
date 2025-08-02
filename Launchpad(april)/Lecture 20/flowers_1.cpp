#include<iostream>

int n, k;

/*
		Motivation: Flowers (basic) :

		Number of ways to eat n flowers, given k.
*/

int F(int n) {

	if (n == 0) {
		// Number of wauys to eat zero flowers is one;
		return 1;
	}

	// I am going to reat the red flower at the current index.
	int op1 = F(n - 1);

	// when i am go8ing to eat the wthie flowers.
	int op2 = 0;

	if (n - k >= 0) {
		op2 = F(n - k);
	}

	// Current state : F(n);

	return op1 + op2;
}


int main() {
	std::cin >> n >> k;

	// I am followring 1 based indexing for boxes.
	std::cout << F(n);
}