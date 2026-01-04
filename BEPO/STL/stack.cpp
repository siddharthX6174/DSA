#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<int> st;
	int x ;
	while (cin >> x) {
		st.push(x);
	}

	while (st.empty() != true) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}