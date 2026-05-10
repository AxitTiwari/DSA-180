// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/submissions/1999717803

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    void add_edge(int u, int v, unordered_map<int, list<int>>& graph) {
        graph[u].push_back(v);
    }

    void dfs(int node, unordered_map<int, list<int>>& graph, unordered_map<int, bool>& visited,
        stack<int>& s
    ) {
        visited[node] = true;

        for (auto nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, graph, visited, s);
            }
        }
        s.push(node);
    }

    vector<int> topo_sort(int n, unordered_map<int, list<int>>& graph) {

        stack<int> s;
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, s);
            }
        }

        vector<int> topo_order;
        while (!s.empty()) {
            topo_order.push_back(s.top());
            s.pop();
        }

        return topo_order;
    }

    void dfs_traverse(int node, int ancestor, unordered_map<int, list<int>>& graph,
        unordered_map<int, bool>& visited, vector<vector<int>>& ans
    ) {

        visited[node] = true;

        for (auto nbr : graph[node]) {
            if (!visited[nbr]) {
                ans[nbr].push_back(ancestor);
                dfs_traverse(nbr, ancestor, graph, visited, ans);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        unordered_map<int, list<int>> graph;
        for (auto edge : edges) {
            add_edge(edge[0], edge[1], graph);
        }

        stack<int> s;
        vector<int> topo_order = topo_sort(n, graph);

        vector<vector<int>> ans(n);
        for (int i = 0; i < topo_order.size(); i++) {
            unordered_map<int, bool> visited;

            dfs_traverse(topo_order[i], topo_order[i], graph, visited, ans);
        }

        for (auto &a : ans) 
            sort(a.begin(), a.end());
        return ans;
    }
};