# include <iostream>
using namespace std;
# include <vector>



int main() {
	int n{};
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int last = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		a[i + 1] = a[i];
	}
	a[0] = last;

	for (auto x : a) {
		cout << x << " ";
	}
	cout << endl;
}