#include<iostream>
using namespace std;

void fun(int* a, int* b) {
	int old_a = (*a);
	int old_b = (*b);
	(*a) = old_a + old_b;
	(*b) = abs(old_a - old_b);
}

int main() {
	int a{};
	int b{};
	cin >> a >> b;

	fun(&a, &b);
	cout << a << "\n";
	cout << b << "\n";
	return 0;
}