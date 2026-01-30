#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[bit] == NULL)
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int findMax(int num) {
        TrieNode* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;

            if (node->child[opp] != NULL) {
                ans |= (1 << i);
                node = node->child[opp];
            } else {
                node = node->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> oQ;
        int q = queries.size();

        for (int i = 0; i < q; i++) {
            // {mi, {xi, index}}
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oQ.begin(), oQ.end());

        Trie trie;
        vector<int> ans(q);
        int ind = 0;
        int n = nums.size();

        for (int i = 0; i < q; i++) {
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qind = oQ[i].second.second;

            while (ind < n && nums[ind] <= mi) {
                trie.insert(nums[ind]);
                ind++;
            }

            if (ind == 0) {
                ans[qind] = -1;
            } else {
                ans[qind] = trie.findMax(xi);
            }
        }

        return ans;
    }
};
