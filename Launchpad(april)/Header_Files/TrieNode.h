# include <iostream>
using namespace std;

template<typename T>

class TrieNode {
public:
	char ch;
	bool terminal;
	unordered_map <char, TrieNode*> childMap;
	int freq; // Mera current node kitni baar visit horh hai
}