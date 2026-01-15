#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

vector<int> EED(int a, int b) {
	if (b == 0) {
		return {1, 0, a};
	}
	/*
		After running line 21 result vector mai ky store hoga:
		bx1+(a%b)y1 = gcd(b, a%b) ka answer.
		but main return kya krna chata hun..
		ax + by = gcd(a, b);
		current_x , current_y representes the solutionn for x1,y1 and with the thelp
		of them i will find x, y
	*/
	vector<int> result = EED(b, a % b);

	int current_x = result[0];
	int current_y = result[1];
	int gcd = result[2];

	int x = current_y;
	int y = current_x - ((a / b) * current_y);

	return {x, y, gcd};
}

int MMI(int a, int m) {

	if (gcd(a, m) != 1) {
		cout << "MMI doesn't exits:\n";
		return -1;
	}

	vector<int> result = EED(a, m);

	int x = result[0]; // This is your MMI.

	return (x + m) % m;
}


int32_t main() {
	// a > b
	int a, m;
	cin >> a >> m ;

	cout << MMI(a, m) << "\n";
	return 0;
}