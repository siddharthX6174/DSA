/*
Iahub got bored, so he invented a game to be played on paper.

He writes n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. He's allowed to do exactly one move: he chooses two indices i and j (1 ≤ i ≤ j ≤ n) and flips all values ak for which their positions are in range [i, j] (that is i ≤ k ≤ j). Flip the value of x means to apply operation x = 1 - x.

The goal of the game is that after exactly one move to obtain the maximum number of ones. Write a program to solve the little game of Iahub.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100). In the second line of the input there are n integers: a1, a2, ..., an. It is guaranteed that each of those n values is either 0 or 1.

Output
Print an integer — the maximal number of 1s that can be obtained after exactly one move.

Examples
InputCopy
5
1 0 0 1 0
OutputCopy
4
*/

#include<iostream>
using namespace std;

int main() {
	int n{};
	cin >> n;

	int cnt0{};
	int cnt1{};
	for (int i = 0; i < n; i++) {
		int a{};
		cin >> a;
		if (a == 0) cnt0++;
		else cnt1++;
	}

	int ans = cnt1;
	if (cnt0 >= 2) {
		ans = ans + 2;
	}
	cout << ans;
}