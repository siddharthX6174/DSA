// #include<iostream>
#include<vector>
#include<iostream>
using namespace std;

// find all repearting elements.
void findRepeat(vector<int>& a) {
	int i = 0;
	int j = 1;
	while (j < a.size()) {
		if (a[j] == a[i]) {
			cout << a[j] << " ";
			// skip duplicates
			while (j < a.size() and a[j] == a[i]) {
				j++;
			}
			i = j;
			j = j + 1;
		} else {
			j++;
			i++;
		}
	}
	return;
}

int main() {
	vector<int>arr;
	int a;
	while (cin >> a) {
		arr.push_back(a);
	}

	// int i = -1, j = 0;
	// while (j < arr.size()) {
	// 	if (arr[i] != arr[j]) {
	// 		cout << arr[j] << " ";
	// 		i = j;
	// 		j++;
	// 	} else {
	// 		j++;
	// 	}
	// }

	findRepeat(arr);
	cout << endl;
	return 0;
}

/*
	leetcode
	class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i=0;
        for (int j=1; j<nums.size(); j++){
            if (nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
*/