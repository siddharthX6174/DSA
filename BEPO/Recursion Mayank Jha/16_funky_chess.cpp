#include<iostream>
using namespace std;
#include<algorithm>

int n;
int grid[10][10] = {};
int total_boxes_where_knight_can_travel = 0;
int ans = 0;

/*
	ans -> maximum number of boxes where the knight can travel in a single path
	across all paths.
	count -> No of boxes where the knight can travel in the current path

	1. (0, 0)  ----->   (dx[0],dy[0])
	2. (0, 0)  ----->   (dx[1],dy[1])
	3.
	4.
	5.
	6.
	7.
	8. (0, 0) ------> (dx[7],dy[7])

	: (x,y) ----> (x+dx[0], y+dy[0])
*/

int dx[] {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] {2, -2, 1, -1, 2, -2, 1, -1};

void knight(int x, int y, int count) {
	ans = max(ans, count);


	for (int i = 0; i < 8; i++) {

		int x_coordinate = x + dx[i];
		int y_coordinate = y + dy[i];

		if (x_coordinate >= 0 and y_coordinate >= 0 and x_coordinate < n and y_coordinate < n  and
		        grid[x_coordinate][y_coordinate] == 1) {

			grid[x_coordinate][y_coordinate] = 0;

			knight(x_coordinate, y_coordinate, count + 1);

			// backtracking
			grid[x_coordinate][y_coordinate] = 1;
		}
	}

}

void Input_grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				total_boxes_where_knight_can_travel++;
			}
		}
	}
}


int main() {
	cin >> n;
	Input_grid();

	grid[0][0] = 0;
	// and count ko 1 se initialise karo

	knight(0, 0, 1);

	cout << total_boxes_where_knight_can_travel - ans << endl;
	cout << total_boxes_where_knight_can_travel << endl;
	cout << ans << endl;

}