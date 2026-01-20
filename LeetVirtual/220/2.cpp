#include<bits/stdc++.h>
using namespace std;
int maximumUniqueSubarray(vector<int>& nums) {
    int ans = 0, sum = 0;
    int l = 0;
    set<int> st;

    for (int r = 0; r < nums.size(); r++) {
        while (st.count(nums[r])) {
            sum -= nums[l];
            st.erase(nums[l]);
            l++;
        }

        st.insert(nums[r]);
        sum += nums[r];
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }
    cout << maximumUniqueSubarray(nums) << endl;
    return 0;
}