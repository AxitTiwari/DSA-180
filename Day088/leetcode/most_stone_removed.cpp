// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/1975361456

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    // Find with path compression
    int find_parent(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
        }

        if (parent[x] != x) {

            // path compression
            parent[x] = find_parent(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void union_set(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        // avoid collions
        int offset = 10001;

        // Step 1: connect row <---> column
        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + offset;

            // merge row and colmn in union set
            union_set(row, col);
        }

        // Step 2: count unique components
        unordered_set<int> components;
        for (auto &stone : stones) {

            // store all unique components, 
            components.insert(find_parent(stone[0]));  // can use column also
        }

        // Step 3: result
        // in one component you can remove all nodes except one node
        // so = toal nodes that can be removed = total_stones - total_component * 1
        return stones.size() - components.size();
    }
};