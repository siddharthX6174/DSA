#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int directions[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
char directionLabel[] = {'U', 'D', 'L', 'R'};

int n;
char maze[1001][1001];
vector<string> paths;
bool visited[1001][1001] = {{0}};

void F(int x, int y, string ans) {
	if (x == n - 1 && y == n - 1) {
		paths.push_back(ans);
		return;
	}

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0 && maze[nx][ny] == '1') {
			F(nx, ny, ans + directionLabel[i]);
		}
	}

	visited[x][y] = 0;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == '0') {
				visited[i][j] = 1;
			}
		}
	}

	if (maze[0][0] == '0' or maze[n - 1][n - 1] == '0') {
		cout << "";
		return 0;
	}

	F(0, 0, "");

	sort(paths.begin(), paths.end());
	for (int i = 0; i < paths.size(); i++) {
		cout << paths[i] << " ";
	}
	cout << endl;

	return 0;
} S