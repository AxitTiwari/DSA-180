// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/submissions/1999512266

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

        if (v == parent_v) {
            parent[v] = parent[parent_u];
            rank[parent_u]++;
        }

        if (rank[parent_v] > 0 || rank[parent_u] < rank[parent_v]) {
            return;
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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // disjoint set ka union by rank method question ke according modified hai, check kr lena
        // done without help
        DisjointSet ds(n);
        for (auto e : edges) {
            ds.union_by_rank(e[0], e[1]);
        }

        set<int> nodes;
        for (int i = 0; i < n; i++) {
            nodes.insert(ds.find_parent(i));
        }

        vector<int> ans;
        for (auto n : nodes) {
            ans.push_back(n);
        }
        return ans;
    }
};