#include<iostream>
#include<vector>
using namespace std;

vector<int> binaryVector;
void DecimalToBinary(int n) {
	while (n > 0) {
		binaryVector.push_back(n % 2);
		n = n / 2;
	}
	return;
}

int binaryToDecimal() {
	int poweroftwo = 1;
	int ans = 0;
	for (int i = 0; i < binaryVector.size(); i++) {
		ans = ans + poweroftwo * binaryVector[i];
		poweroftwo = poweroftwo * 2;
	}
	return ans;
}

int main() {
	int n{};
	cin >> n;

	DecimalToBinary(n);

	cout << "binary of " << n << " : ";
	for (int& x : binaryVector) {
		cout << x << " ";
	}
	cout << "\n";

	cout << "decimal : " << binaryToDecimal() << "\n";

	return 0;
}