#include <iostream>
#include <vector>
#include <cmath>    // for abs
#include <algorithm> // for min
using namespace std;

int n; // number of stones
vector<int> h; // heights of stones

int front(int i) {

    if (i >= n) {
        return 0;
    }

    int op1 = abs(h[i] - h[i + 1]) + front(i + 1);

    int op2 = INT_MAX;
    if (i + 2 <= n) {
        op2 = abs(h[i] - h[i + 2]) + front(i + 2);
    }

    return min(op1, op2);
}




int main() {
    cin >> n;
    h.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    cout << front(1);
}