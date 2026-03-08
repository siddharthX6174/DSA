#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char a[101][101];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int x, y;
	cin >> x >> y;

	int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

	for (int i = 0; i < 8; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {

			if (a[nx][ny] != 'x') {
				cout << "no";
				return 0;
			}

		}
	}

	cout << "yes";

	return 0;
}