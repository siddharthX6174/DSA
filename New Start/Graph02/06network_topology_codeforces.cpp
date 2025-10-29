#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	int n, m;
	vector<int> degree;

	Graph(int n, int m) {
		this->n = n;
		this->m = m;
		degree.assign(n + 1, 0);
	}

	void addEdge(int x, int y) {
		degree[x]++;
		degree[y]++;
	}

	void ans() {
		int cnt1 = 0, cnt2 = 0, cntMax = 0;

		for (int i = 1; i <= n; i++) {
			if (degree[i] == 1) cnt1++;
			else if (degree[i] == 2) cnt2++;
			else if (degree[i] == n - 1) cntMax++;
		}

		if (m == n - 1 && cnt1 == 2 && cnt2 == n - 2)
			cout << "bus topology\n";
		else if (m == n && cnt2 == n)
			cout << "ring topology\n";
		else if (m == n - 1 && cntMax == 1 && cnt1 == n - 1)
			cout << "star topology\n";
		else
			cout << "unknown topology\n";
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Graph gr(n, m);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y);
	}

	gr.ans();
	return 0;
}
