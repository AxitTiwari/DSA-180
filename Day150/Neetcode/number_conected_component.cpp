// https://neetcode.io/problems/count-connected-components/question

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        for (auto edge : edges) {
            add_edge(edge[0], edge[1]);
        }

        int count = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited);
                count++;
            }
        }
        return count;
    }
private:
    unordered_map<int, list<int>> graph;

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int node, unordered_map<int, bool> &visited) {

        visited[node] = true;

        for (auto nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited);
            }
        }
    }
};
