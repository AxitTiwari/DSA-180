// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/submissions/1997805845

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<pair<int, bool>>>& graph) {
        graph[u].push_back({v, true});
        graph[v].push_back({u, false});
    }

    int dfs(int node, unordered_map<int, list<pair<int, bool>>>& graph,
        unordered_map<int, bool>& visited
    ) {

        visited[node] = true;

        int ans = 0;
        for (auto [nbr, true_edge] : graph[node]) {

            if (!visited[nbr]) {
                
                if (true_edge) {
                    ans += 1 + dfs(nbr, graph, visited);
                }
                else {
                    ans += dfs(nbr, graph, visited);
                }
            }
        }
        return ans;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, list<pair<int, bool>>> graph; // node : nbr, true_edge
        for (auto connection : connections) {
            add_edge(connection[0], connection[1], graph);
        }

        unordered_map<int, bool> visited;
        int min_edges_changed = dfs(0, graph, visited);

        return min_edges_changed;
    }
};