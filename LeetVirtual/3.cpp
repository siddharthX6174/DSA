#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& stones) {
    int i = 0;
    if (stones.back() < stones.front()) {
        i = stones.size() - 1;
    }

    int score = stones[i];

    if (i == 0) {
        stones.erase(stones.begin());
    } else {
        stones.pop_back();
    }

    return score;
}
int stoneGameVII(vector<int>& stones) {
    int stone_sum = stones[0];
    for (int i = 1; i < stones.size(); i++) {
        stone_sum += stones[i];
    }

    int alice_score = stone_sum - solve(stones);
    int bob_score = 0;

    int cnt = 1;

    while (stones.size() > 0) {
        if (cnt % 2 == 0) {
            bob_score += stone_sum - solve(stones);
        }
        alice_score += stone_sum - solve(stones);
    }

    return alice_score - bob_score;
}


int main() {
    vector<int> stones;
    int x{};
    while (cin >> x) {
        stones.push_back(x);
    }
    cout << stoneGameVII(stones);
    return 0;
}