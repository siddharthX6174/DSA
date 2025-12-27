#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
class Pair1 {
public:
	T1 first;
	T2 second;

	Pair1() {}  // default constructor (IMPORTANT)

	Pair1(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}
};

int main() {
	Pair1<int, int> yo;

	yo.first = 100;
	yo.second = 200;

	cout << yo.first << " " << yo.second << endl;

	// array of pairs
	Pair1<string, int> arr[10];

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < t; i++) {
		cout << arr[i].first << " -> " << arr[i].second << endl;
	}

	return 0;
}
