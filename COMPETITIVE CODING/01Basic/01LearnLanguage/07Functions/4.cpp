#include<iostream>
#include<vector>
using namespace std;

bool f2(int n) {
	vector<int> a;

	while (n > 0) {
		a.push_back(n % 2);
		n = n / 2;
	}

	bool ans = true;
	int i = 0, j = a.size() - 1;

	while (i < j) {
		if (a[i] != a[j]) {
			ans = false;
			break;
		}
		i++;
		j--;
	}

	return ans;
}

bool f1(int n) {
	return (n % 2 == 1);
}

int main() {
	int n;
	cin >> n;

	bool a = f1(n);
	bool b = f2(n);

	if (a && b) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}



	return 0;
}