#include <iostream>
#include <vector>
#include <algorithm>

// Global
std::vector<int> cost;
int n;
//------------------------------------------------------------------------------------------


int F(int x) {
    /*
        BP : Reach from 0 to nth stair
        SP : Reach from 1 to nth stair
                      or
             Reach from 2 to nth stair


    */

    if (x >= n) return 0;

    int op1 = cost[x] + F(x + 1);
    int op2 = cost[x] + F(x + 2);

    return std::min(op1, op2);
}

// --------------------------------------------------------------------------------------------



int main() {
    int x;
    while (std::cin >> x) {
        cost.push_back(x);
    }
    n = cost.size();

    /*
        i want to check wheter it is more good from starting with 0 index or 1 index.
    */
    int ans = std::min(F(0), F(1));
    std::cout << ans << std::endl;
}
