#include<iostream>
#include"../Header_Files/Stack.h"
using namespace std;


int main() {

	Stack<int>s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.push(x);
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}


}