#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// string s = "";

// void solve (int n){
// 	if (n == 1) {
// 		s += "1 ";
// 		return;
// 	}

// 	string k;
// 	k += solve(n-1);
// 	k += " ";
// 	k += n;
// 	k += " ";
// 	k += solve(n-1);
// 	k += " ";
// 	return (s += k);
// }

/*
	over complicating don't use string print during execution
*/

void solve (int n) {
	if (n == 1) {
		cout << "1";
		return;
	}
	solve (n - 1);
	cout << " " << n << " ";
	solve (n - 1);
}

int main() {
	fast();

	int n;
	cin >> n;

	solve(n);

	return 0;
}