# include <iostream>
# include<vector>


void print(int arr[], int index, int n, int sum, std::vector<int>& ans) {
	if (index == n) {
		ans.push_back(sum);
		return;
	}
	//no
	print(arr, index + 1, n, sum, ans);
	// yes
	print(arr, index + 1, n, sum += arr[index], ans);
}

int main() {
	int arr[] {1, 2, 3, 4};
	int target = 10;
	std::vector<int> ans;
	print(arr, 0, 4, 0, ans);
	for (int i{}; i < ans.size(); i++) {
		//std::cout << ans[i] << std::endl;
		if (ans[i] == target) {
			std::cout << "true" << std::endl;
			break;
		}
	}
	//std::cout << "false" << std::endl;
}