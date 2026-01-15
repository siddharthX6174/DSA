#include<bits/stdc++.h>
using namespace std;

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


int main() {
	int a, b;
	cin >> a >> b;

	vector<int> ans = EED(a, b);

	cout << ans[0] << " " << ans[1] << " " << ans[2] << " \n";
	cout << gcd(a, b) << "\n";
	return 0;
}