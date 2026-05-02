// https://leetcode.com/problems/redundant-connection/submissions/1993091376

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

    bool union_by_rank(int u, int v) {

        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        // same component
        if (parent_u == parent_v) return true;

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
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        // graph -> changing dynamically, 
        // cycle detection is becoming so harder, : use disjoint set

        DisjointSet ds(edges.size());
        for (auto edge : edges) {
            
            // find if two nodes have same parent -> 
            if (ds.union_by_rank(edge[0], edge[1])) {
                return {edge[0], edge[1]};
            }
        }
        return {};
    }
};