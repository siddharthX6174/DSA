#include<iostream>
using namespace std;
#include<vector>

int main() {
	int bit;
	int count{};
	vector<int> bits;

	while (std::cin >> bit) {
		bits.push_back(bit);

		if (bit == 1) {
			count ++;
			if (count == 5) {
				bits.push_back(0);
				count = 0 ;
			}

		}
		else {
			count = 0;
		}
	}



}