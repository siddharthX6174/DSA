#include<iostream>
#include<climits>
using namespace std;

int main() {
	int a{};
	int mini = INT_MAX;
	int maxi = INT_MIN;
	while (cin >> a) {
		mini = min(mini, a);
		maxi = max(a, maxi);
	}

	cout << mini << " " << maxi << "\n";
	return 0;
}

