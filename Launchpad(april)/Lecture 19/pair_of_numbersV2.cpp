
#include<iostream>
#include<climits>

int n{};
int ans{INT_MAX};


// Now we are thinking about applying recursion from back.

// BP: You are at n and you want to calculate
//     min steps to reach 1,1.

/*
	Challenge:
	1. How do I write this n as a pair?
		What all pairs are avalable that can make n. (sum).
		n-1, 1
		n-2, 2
		n-3, 3
		n-4, 4
		- - - - - - - -
		n = 5 : (4,1) , (3,2) , (2,3), (1,4)

	2. While moving forward:
		a,b ---> a+b,b or or a, a+b.
		but while moving backwards:
		a,b ---> a-b, b or a, b-a.

		Only one term out of a-b/ b-a can be positive and if koi term not positive that
		cannot be considered as a start.
*/




/*
int F(int a, int b) {

	if (a > n or b > n) {
		return 1e8;
	}

	if (a == n or b == n) {
		return 0;
	}

	int op1 = 1 + F(a + b, b);
	int op2 = 1 + F(a, a + b);

	// Then what is the answer for F(a,b);

	return std::min(op1, op2);
}
*/

void F2 (int a, int b, int count) {
	if (a == 1 and b == 1) {
		// If you reach 1,1 that means you have found a path
		// now compare your current path
		// steps to universal path steps
		// whichever is min is your answer
		ans = std::min(ans, count);
		return;
	}

	if (a - b > 0) {
		F2 (a - b, b, count + 1);
	}
	if (b - a > 0) {
		F2(a, b - a, count + 1);
	}

	return;
}


int main() {
	std::cin >> n;

	//std::cout << F(1, 1) << std::endl;


	for (int i{1}; i <= n; i++) {
		// pairs are: (n-i, i)

		// nowmy Problems becomes:
		// min steps to reach 1,1 from (n-i,i).

		// currently my count is 1.
		// beacuse in one step you reach the pair n-i,9 form n
		F2(n - i, i, 1);
	}

	std::cout << ans << std::endl;

}


/*
	F2(n-i, i, 1): Min steps to reach 1,1 form n-i, i is given by ans
	and my current path has coumnt no of steps to reach 1,1.

	count : this tells you in how many steps you reach 1,1 in this current paht

	cout: maine current
*/