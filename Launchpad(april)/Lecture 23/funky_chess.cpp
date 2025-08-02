#include <iostream>
using namespace std;
const int N = 10;

/*
	AAp x,y par khade ho knight ke 9 moves kya honge?
	x+dx[i] , y+dy[i] where i goes from 0 to 7 index
	in dx and dy array.
*/

int dx[] {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] {2, -2, 2, -2, 1, -1, 1, -1};
int n;
int grid[N][N] {};
int Total_boxes{};

// Take input seperately
void input() {
	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_boxes++;
			}
		}
	}
}

/*
	F(0,0): It returns me the maximum boxes the knight can travel from 0,0 without visiting a box again
	in the current path.

	NOw I don't want to return anything.
	Har path me can kitna travel kar payay  usko calcualte  karo and ek global mazimum rakho jo ye batata hain
	ki accross all paths knight maximum kitne boxes ko travel kar paya .

	F(0,0,count): Count hume ye batata hain ki current raste me aapne kitne boxes knight se
	visite kar liye hain.

	global mazimum ke liye :
	ans;
*/

int ans = -1; // THis variable stores the mximum boxes the knight was able to travel
// accross all the paths.

void F(int x, int y, int count) {
	ans = max(ans, count);
	/*
		Curenlty i am x,y  co-ordingates and I am trying to solve for the state: F(x,y,count).

		There are 8 new pahts form this x,y cooredinate:
		Main har path ke liye recursion call karna chathta hu:
		ye ya toh main manually karlu ya for loop se.
	*/

	for (int i{}; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// Ceheck if this current nx, ny co-ordinate is vlaid or not.

		/*
			How to check this:
			1. Matri ke andar hona chaiye.
			2. Current path me visited nahi hona chahiiye.
		*/

		if (nx >= 0 and nx<N and ny >= 0 and ny < N and grid[nx][ny] == 1) {
			// Now i am going to this new box, hence this box becomes part of the curent path
			// so make this box unavailabale for the future iteration in the cuurent path only.

			grid[nx][ny] = 0;
			F(nx, ny, count + 1);

			// If i am standing at this lline that means:
			// Recursin has already calculated the answer for
			// nx, ny coordinates that means Now This box should be avalable for future
			// and then we reverse the task

			grid[nx][ny] = 1;
		}

	}
}

int main() {
	cin >> n;
	input();


	grid[0][0] = 0; // Why make this box zero inititally?
	// Because this box is common in all the paths and I don;t want to revisit it again.

	/*
		Agar grid[x][y] = 1 hain to aap x,y par jaaskte ho varma agar 0 hain to aap nahi jaaskte.
		Instead of maintaing a new visited array i am doing
		the visited
	*/
	F(0, 0, 1);

	cout << Total_boxes - ans << endl;
}