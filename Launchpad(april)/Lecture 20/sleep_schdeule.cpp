#include<iostream>
# include <algorithm>
/*
	n = 5:

	F(5,x):  Maine 0 se 4 sleep kali iska matlab hai
	maine 5 sleep as a count karli : ab meri
	maximum number of sleep kya hogi 0 //

	- - - - -
	0 1 2 3 4

	Definition : F(5, x): Maximum numbr of sleep from 5th index to 4th is zero. (Not Possible)

*/

int n, h, l, r;
int a[20001];



int F(int index, int waking_Time) {
	if (index == n) {
		return 0;
	}

	// kya meri next sleep jo a[index] ghnte baad hogi ky wo good sleep hain?
	// above question ka anwer main ans1 name ke variable main rakuga
	int x = (waking_Time + a[index]) % h;
	int ans1 = 0;
	if (x >= l and x <= r) {
		ans1 = 1;
	}

	// kya meri next sleep jo a[index]-1 ghnte baad hogi ky wo good sleep hain?
	// above question ka anwer main ans2 name ke variable main rakuga
	int y = (waking_Time + a[index] - 1) % h;
	int ans2 = 0;
	if (y >= l and y <= r) {
		ans2 = 1;
	}

	// when nesxt sleep is after a[index] hours.
	int op1 = ans1 + F(index + 1, x);

	// when next sleep is after a[index] - 1 hours.
	int op2 = ans2 + F(index + 1, y);

	return std::max(op1, op2);
}


int main() {
	std::cin >> n >> h >> l >> r;
	for (int i{}; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << F(0, 0) << std::endl;
}