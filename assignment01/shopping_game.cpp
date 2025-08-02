#include <iostream>

int main() {
	int t{};
	std::cin >> t;

	while (t--) {
		int ayush_limit{}, harshit_limit{};
		std::cin >> ayush_limit >> harshit_limit;

		int turn = 1;  // Start from turn 1

		while (true) {
			if (turn % 2 != 0) {  // Aayush's turn (odd)
				if (ayush_limit >= turn) {
					ayush_limit -= turn;
				} else {
					std::cout << "Harshit\n";
					break;
				}
			} else {  // Harshit's turn (even)
				if (harshit_limit >= turn) {
					harshit_limit -= turn;
				} else {
					std::cout << "Aayush\n";
					break;
				}
			}
			turn++;
		}
	}

	return 0;
}


























/*# include <iostream>
# include <algorithm>

int main() {
	int t{};
	std::cin >> t;

	int ayush_limit{}, harshit_limit{};
	std::cin >> ayush_limit >> harshit_limit;

	while ((std::max(ayush_limit, harshit_limit)--)){
		int sum_ayush{}, sum_harshit{}, ayush_buy_count{}, harshit_buy_count{};

		for (int i{1}; i<INT_MAX; i++){
			sum_ayush += i;
			if (sum_ayush <= ayush_limit) {
				ayush_buy_count++;
			}
			i++;
			sum_harshit += i;
			if (sum_harshit <= harshit_limit){
				harshit_buy_count++;
			}
		}

		if (ayush_buy_count > harshit_buy_count){
			std::cout << "Aayush";
		}else{
			std::cout << "Harshit";
		}
	}

	return 0;
}*/