# include <iostream>
# include <map>
# include <list>
# include <utility>
# include <algorithm>
using namespace std;

template<typename T>
class gr {
private:
	//map<T, vector<T>>mp ; // Adj. List
	map<T, list<T>> mp;

public:

	void AddEdge(T x, T y, bool direction) {
		map[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	// Print The Adj. List :
	void Print() {
		for (pair<T, list<T>> x : mp) {
			T node = x.first;
			list<T> nbrs = x.second;

			cout << node << " : ";

			for (T nbr : nbrs) {
				cout << nbr << " ";
			}
			cout << endl;
		}
		cout << "------------------------------" << endl;
	}

};


int main() {
	int n, m , direction;
	cin >> n >> m >> direction;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y ;
		gr.AddEdge(x, y, direction);
	}

	gr.Print();

}