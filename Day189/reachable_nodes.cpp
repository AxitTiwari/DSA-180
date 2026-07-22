// https://leetcode.com/problems/reachable-nodes-with-restrictions/submissions/2075477074

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        for (auto &edge : edges) {
            add_edge(edge[0], edge[1]);
        }

        unordered_set<int> res;
        for (int r : restricted) {
            res.insert(r);
        }

        if (res.find(0) != res.end()) return 0;

        return reachable_nodes(0, res) + 1;
    }
private:
    unordered_map<int, list<int>> graph;
    unordered_set<int> visited;
    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int reachable_nodes(int node, unordered_set<int>& restricted) {

        visited.insert(node);

        int num_of_nodes = 0;
        for (auto nbr : graph[node]) {

            if (restricted.find(nbr) != restricted.end()) continue;

            if (visited.find(nbr) != visited.end()) continue;

            num_of_nodes += reachable_nodes(nbr, restricted) + 1;
        }
        return num_of_nodes;
    }
};