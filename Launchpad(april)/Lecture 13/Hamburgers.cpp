#include <iostream>

bool check(long long mid, long long nb, long long ns, long long nc, long long pb, long long ps, long long pc, long long sb, long long ss, long long sc, long long r) {
	long long mb = ((sb * mid) - nb) * pb;
	if (mb < 0) mb = 0;

	long long ms = ((ss * mid) - ns) * ps;
	if (ms < 0) ms = 0;

	long long mc = ((sc * mid) - nc) * pc;
	if (mc < 0) mc = 0;

	long long total = mb + ms + mc;

	return total <= r;
}

int main() {
	int t{};
	std::cin >> t;
	while (t--) {
		char ch[101] {};
		std::cin >> ch;

		int pb{}, ps{}, pc{};
		int nb{}, ns{}, nc{};
		long long r{};
		int sb = 0, ss = 0, sc = 0;

		std::cin >> nb >> ns >> nc;
		std::cin >> pb >> ps >> pc;
		std::cin >> r;

		// Count the required number of B, S, C in the recipe
		for (int i = 0; ch[i] != '\0'; i++) {
			if (ch[i] == 'B') sb++;
			else if (ch[i] == 'S') ss++;
			else if (ch[i] == 'C') sc++;
		}

		long long s = 0, e = 1e13, ans = 0;

		while (s <= e) {
			long long mid = (s + e) / 2;

			// Convert all to long long when passing to check
			if (check(mid, nb, ns, nc, pb, ps, pc, sb, ss, sc, r)) {
				ans = mid;
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
