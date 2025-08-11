#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


/*
	Associative Containers:Map,Unordered_Map
	set,unordered_set,multimap,multiset


	Map : Ordered_Map
	Map is also a dsa jo aapke liye mapping create karta hain
	between key and value where key is same as index in array.

	Map has properties of arrays and Self balancing BSTs.

	//Arrays:
	Map : Data is sorted based on keys.
	Map : Map me only unique keys can be inserted.

	//BSTs:
	Map: Searching/Insertion/Deletion can be done in Log2(n).

	Unordered_Map:
	Map: Key and value
	Unordered_Map are made using the principle of Hashing.

	Hashing Principle ke karan :
	Is map me data ke pass sirf unique keys hosakti hain.
	Data is not sorted based on keys.


	Since we are using the principle of hashing :
	that means : Searching/Insertion/Deletion in average scenario is in
	constant computation.
	and worst case scenario is n compution.


	map is a dsa which contains a pair of key and value.

	map/unordered map if you have not inserted a key and you are
	searching for a key that is not present you will get a
	value as zero.

*/


int main() {

	map<string, int>mp;
	unordered_map<string, int>ump;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;

		//Insertion
		// pair<string, int>p = make_pair(s, x);
		// mp.insert(p);
		// mp.insert(make_pair(s, x));

		ump.insert({s, x});

		//Updation
		//mp[s] = x;
	}

	// for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
	// 	cout << (*it).first << " " << it->second << endl;
	// }

	cout << endl << endl << endl;
	for (pair<string, int> x : ump) {
		cout << x.first << " " << x.second << endl;
	}

	cout << mp["Mayank"] << endl;
	mp["Samyak"] = 90861;

	if (ump.count("Mayank") == 1) {
		cout << "yo" << endl;
	}

	if (ump.find("Ramesh") != mp.end()) {
		cout << "Yo";
	} else {
		cout << "hihi";
	}

}