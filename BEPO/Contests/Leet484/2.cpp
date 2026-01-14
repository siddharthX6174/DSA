#include<bits/stdc++.h>
using namespace std;


int centeredSubarrays(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        set<int> st;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            st.insert(nums[j]);
            if (st.count(sum)) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    int a{};
    while (cin >> a) {
        nums.push_back(a);
    }
    cout << centeredSubarrays(nums);
}