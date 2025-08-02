// find all duplicates in the array


# include <iostream>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int nums[n] {};
	int maxi = INT_MIN;
	for (int i{}; i < n; i++) {
		std::cin >>  nums[i];
		maxi = std::max(maxi, nums[i]);
	}

	int freq_arr[maxi + 1] {};

	for (int i{}; i < n; i++) {
		freq_arr[nums[i]] ++;
	}

	std::cout << "[ ";
	for (int i{}; i < maxi + 1; i++) {
		if (freq_arr[i] > 1) {
			std::cout << i << ", ";
		}
	}
	std::cout << "]";

	std::cout << std::endl;
	return 0;

}


// leetcode


/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        vector<int> freq_arr(maxi + 1, 0);  // dynamic allocation
        vector<int> result;

        for (int i = 0; i < n; i++) {
            freq_arr[nums[i]]++;
        }

        for (int i = 0; i <= maxi; i++) {
            if (freq_arr[i] > 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};
*/