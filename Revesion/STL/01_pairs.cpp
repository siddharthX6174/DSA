#include<bits/stdc++.h>
using namespace std;

int main() {
	pair<string, int> p;
	//p = make_pair("shraddha", 500);
	p = {"shraddha", 500};

	pair<string, int> p1 = p;

	//cout << p1.first << " : " << p1.second << endl;

// --------------------------------------------------------

	vector<pair<string, int>> money;

	money.push_back({"shraddha", 1999});
	money.push_back({"siddharth", 2000});
	money.push_back({"vaibhav", 200});

	for (int i = 0; i < money.size(); i++) {
		cout << money[i].first << " : " << money[i].second << endl;
	}

	cout << "\nafter swapping ----------\n\n";

	swap(money[0], money[1]);
	for (int i = 0; i < money.size(); i++) {
		cout << money[i].first << " : " << money[i].second << endl;
	}




}