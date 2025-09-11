# include <iostream>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		multiset<int> xc, yc, sx, sy;

		xc.insert(0);
		xc.insert(n);
		yc.insert(0);
		yc.insert(m);

		sx.insert(n);
		sy.insert(m);

		for (int i = 0; i < q; i++) {

			int a, n;
			cin >> a >> b;

			if (a == 0) {
				// Division is vertical x = b.
				if (xc. find(b) != xc.end()) {
					// you have already made a division on this co-ordinate
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				multiset<int>::iterator small = (--sx.lower_bound(b));
				multiset<int>::iterator large = sx.upper_bound(b);

				int Length = (*large - *small);
				sx.erase(sx.find(Length));

				sx.insert(b - *small);
				sx.insert(*large - b);

				xc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;

			} else {
				// create a division in y = b;

				if (yc. find(b) != yc.end()) {
					// you have already made a division on this co-ordinate
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				multiset<int>::iterator small = (--sy.lower_bound(b));
				multiset<int>::iterator large = sy.upper_bound(b);

				int Length = (*large - *small);
				sy.erase(sy.find(Length));

				sy.insert(b - *small);
				sy.insert(*large - b);

				yc.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());
				cout << LargestXSegment*LargestYSegment << endl;
			}
		}
	}
}