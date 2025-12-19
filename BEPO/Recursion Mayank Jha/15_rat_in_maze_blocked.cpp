#include<iostream>
using namespace std;

/*
	solution[x][y] = 1 that means this x,y is the part of path reaching the destination.
	visited[x][y] = 1 Means you have already visited this x,y and you don't need to revisit it again

*/

bool solution[1001][1001] = {{}};
bool visited[1001][1001] = {{}};
int n{}, m{};
char maze[1001][1001];


bool RatInMaze(int x, int y) {

	if (x == n - 1 and y == m - 1) {
		/*
			This means Ihave reached the desired box so i have to inform my parent recursion
			that i have found a solution and also i have to print the matrix
		*/

		solution[x][y] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}
	/*
		currently you are at the poisition x,y and there are two moves. : ->, down
		-> right : (x, y+1)
		-> down : (x+1, y)
	*/

	/*
		Steps:
		1. whenever you go to any box check it is not visited
		2. if above condition got satisfied that means you have landed at the correct box;
			now make this box as a part of your solution and mark it as visitedd
	*/

	if (visited[x][y] == 1) {
		return false;
	}

	// ek baar kaam m karuga baaki ka recursion karega
	solution[x][y] = 1;
	visited[x][y] = 1;

	// i will ask recursion you can go to its right , please go and if you find a path then also
	// tell me and if you don't find a path then also tell me. and if you find a path then
	// print the path uptill solution

	if (y + 1 <= m and visited[x][y + 1] == 0) { // now i can go to right
		bool rightans = RatInMaze(x, y + 1);
		if (rightans == 1) {
			return true;
		}
	}

	// ab m down jane ki kosis karuga
	if (x + 1 <= n and visited[x + 1][y] == 0) {
		bool downans = RatInMaze(x + 1, y);
		if (downans == 1) {
			return true;
		}
	}

	/*
		if youu are standing here now that means you were not able to from right and down from
		this position and hence box(x, y) can never be part of your solution so make this box as out
		of solution
	*/

	solution[x][y] = 0; // backtrack
	return false;

}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'x') {
				visited[i][j] = 1;
			}
		}
	}

	bool ans = RatInMaze(0, 0);

	if (ans == 0) {
		cout << "-1" << endl;
	}


	return 0;
}