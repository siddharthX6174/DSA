#include<bits/stdc++.h>
using namespace std;

string reformatNumber(string number) {
	string s = "";
	for (auto x : number) {
		if (x != ' ' && x != '-') {
			s += x;
		}
	}
	int size = s.size();

	string dummy = "";
	int l = 1;
	for (auto x : s) {
		if (size % 3 == 0) {

		}
	}





	return s;
}

int main() {
	string s;
	getline(cin, s);
	cout << reformatNumber(s) << endl;
	return 0;
}
