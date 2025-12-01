// 2d matrix m every row ka sum print kardo
#include <iostream>
using namespace std;

int main() {
	int r{}, c{};
	cin >> r >> c;

	int a[r][c] {{}};

	for (int i = 0; i < r; i++) {
		int sum{};
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		cout << sum << endl;
	}
	cout << "-----------------\n";



	// ab row ko col ki form m print karo and col ko row

	for (int i = 0; i < c; i++) {
		int sum{};
		for (int j = 0; j < r; j++) {
			cout << a[j][i] << "  ";
			sum += a[j][i];
		}
		cout  << " ---> " << sum ; // har ek column ka sum
		cout << endl;
	}

	// 2d array k diagonals print krne hai
	cout << "----------diagonal printing-------\n";

	// printing primary diagonal

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j) {
				cout << a[i][j] << "  ";
			}
		}
		cout << endl;
	}

	// printing secondary digronal
	cout << "seccondary diganoal \n";

	for (int i = 0; i < r; i++) {
		for (int j = c - 1; j >= 0; j--) {
			if (i + j == c - 1) {
				cout << a[i][j] << "  ";
			}
		}
		cout << endl;
	}


	return 0;
}