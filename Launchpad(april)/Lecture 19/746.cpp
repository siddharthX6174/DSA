#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

/*
    BP : Reach from 0 to nth stair
    SP : Reach from 1 to nth stair
            or
            Reach from 2 to nth stair


*/


int F(int x) {

    // base case--
    if (x == n) {
        cost[x] = 0;
    }
    int op1 = cost[x] + F(x + 1);
    int op2 = cost[x] + F(x + 2);

    return std::min(op1, op2);
}






// -----------------------------------------------
int n{};
std::vector<int> cost;

int x;
while (std::cin >> x) {
    cost.push_back(x);
    n++;
}

std::cout << n << std::endl;
// ---------------------------------------------------


int main() {


    /*
        i want to check wheter it is more good from starting with 0 index or 1 index.
    */

    int potential_answer_1 {F(0)}, potential_answer_2 {F(1)};
    int ans = std::min(potential_answer_1, potential_answer_2);
    std::cout << ans << std::endl;
}
