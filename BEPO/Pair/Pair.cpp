#include<bits/stdc++.h>
using namespace std;

class Pair1 {
public:
	int first;
	int second;

	Pair1() {
		first = 0;
		second = 0;
	}

	Pair1(int first, int second) {
		this->first = first;
		this->second = second;
	}
};

int main() {
	Pair1 yo;

	yo.first = 100;
	yo.second = 200;

	cout << yo.first << " " << yo.second;
}