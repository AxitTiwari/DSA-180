// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/submissions/1999055033

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class Solution {
private:
    void add_edge(int u, int v, int w, unordered_map<int, list<pair<int, int>>>& graph) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    void dijistra_sortest_path(
        int n,
        vector<int>& dist, 
        unordered_map<int, list<pair<int, int>>>& graph
    ) {

        dist[n] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
        pq.push({0, n});

        while (!pq.empty()) {

            auto [w, node] = pq.top();
            pq.pop();

            for (auto &[nbr, wt] : graph[node]) {

                if (w + wt < dist[nbr]) {
                    dist[nbr] = w + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
    }

    int dfs(int src, int dest, unordered_map<int, list<pair<int, int>>>& graph,
        vector<int>& dist, unordered_map<int, bool>& visited, vector<int>& dp
    ) {

        if (src == dest) {
            return 1;
        }

        if (dp[src] != -1) {
            return dp[src];
        }

        visited[src] = true;

        int paths = 0;
        for (auto &[nbr, wt] : graph[src]) {

            if (!visited[nbr]) {

                if (dist[src] > dist[nbr]) {
                    paths = (paths + dfs(nbr, dest, graph, dist, visited, dp)) % MOD;

                    // backtrack ** imp
                    visited[src] = false;
                    cout << src << ": " << nbr << endl;
                }
            }
        }
        return dp[src] = paths;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, list<pair<int, int>>> graph;
        for (auto edge : edges) {
            add_edge(edge[0], edge[1], edge[2], graph);
        }

        vector<int> dist(n+1, INT_MAX);
        dijistra_sortest_path(n, dist, graph);

        unordered_map<int, bool> visited;
        vector<int> dp(n+1, -1);
        int restricted_paths = dfs(1, n, graph, dist, visited, dp);
        return restricted_paths;
    }
};