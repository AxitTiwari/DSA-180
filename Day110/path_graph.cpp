// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/1994407409

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, list<int>> graph;
    unordered_map<int, bool> visited;

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool dfs(int src, int dest) {

        visited[src] = true;

        if (src == dest) return true;

        for (auto nbr : graph[src]) {
            if (!visited[nbr]) {
                if (dfs(nbr, dest)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        for (int i = 0; i < edges.size(); i++) {
            
            add_edge(edges[i][0], edges[i][1]);
        }

        return dfs(source, destination);
    }
};