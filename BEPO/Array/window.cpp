

class Solution {
public:
	int findLHS(vector<int>& nums) {
		deque<int> maxdq, mindq;
		int left = 0, ans = 0;

		for (int right = 0; right < nums.size(); right++) {

			// 🔺 maintain max deque (decreasing)
			while (!maxdq.empty() && nums[maxdq.back()] < nums[right])
				maxdq.pop_back();
			maxdq.push_back(right);

			// 🔻 maintain min deque (increasing)
			while (!mindq.empty() && nums[mindq.back()] > nums[right])
				mindq.pop_back();
			mindq.push_back(right);

			// ❌ shrink window if invalid
			while (nums[maxdq.front()] - nums[mindq.front()] > 1) {
				left++;
				if (maxdq.front() < left) maxdq.pop_front();
				if (mindq.front() < left) mindq.pop_front();
			}

			// ✅ valid window ONLY when diff == 1
			if (nums[maxdq.front()] - nums[mindq.front()] == 1) {
				ans = max(ans, right - left + 1);
			}
		}
		return ans;
	}
};
