#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int two = INT_MIN;

        for (int i = nums.size() - 1 ; i >= 0; i--) {


            // while the stack is not empty and current element is greater than
            // top of the stack remove it or pop it
            while (!s.empty() and nums[i] > s.top()) {
                two = max(three, st.top());
                s.pop();
            }

            if (nums[i] < two) {
                return true;
            }

            // push the current element in stack;
            s.push(nums[i]);
        }
        return false;
    }
};


int main() {

}