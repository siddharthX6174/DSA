#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string s;
	cin >> s;

	map<char, int> mp;

	for (char& c : s) {
		mp[c]++;
	}

	for (auto& x : mp) {
		char c = x.first;
		int v = x.second;
		cout << c << " : " << v;
		cout << "\n";
	}

	return 0;
}