// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/2033597338

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        vector<array<int, 3>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet dsu(n);

        int min_dist = 0;
        for (auto &[dist, u, v] : edges) {

            if (dsu.find_parent(u) == dsu.find_parent(v)) continue;

            min_dist += dist;
            dsu.union_by_rank(u, v);
        }
        return min_dist;
    }
};