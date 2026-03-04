#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	if ((s[0] - '0') % 2 == 0 ) {
		cout << "EVEN";
	} else {
		cout << "ODD";
	}
	return 0;
}