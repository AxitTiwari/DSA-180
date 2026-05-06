// https://leetcode.com/submissions/detail/1996511036/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {

        rank.resize(n+1, 0);
        parent.resize(n+1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return;

        if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        DisjointSet ds(1002);

        for (auto equation : equations) {

            char u = equation[0];
            char v = equation[3];
            char opr = equation[1];

            // group1 : all variables having equal value
            if (opr == '=') {
                ds.union_by_rank(u -'a'+1, v-'a'+1);
            }
        }

        for (auto equation : equations) {

            char u = equation[0];
            char v = equation[3];
            char opr = equation[1];

            // group2 : all variables having opposite value : should have differnet parent
            if (opr == '!') {
                
                if (ds.find_parent(u-'a'+1) == ds.find_parent(v-'a'+1)) return false;
            }
        }
        return true;
    }
};