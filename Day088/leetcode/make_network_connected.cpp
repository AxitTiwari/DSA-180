// https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/1975007901

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, list<int>> adj_list;

    void dfs(int node, unordered_map<int, bool>& visited) {

        visited[node] = true;

        for (auto nbr : adj_list[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited);
            }
        }
    }

    void inisialise_graph(int n) {

        for (int node = 0; node < n; node++) {
            adj_list[node];
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (n - 1 > connections.size()) return -1;

        // very important : you have forgot this
        inisialise_graph(n);
        
        for (int row = 0; row < connections.size(); row++) {

            int u = connections[row][0];
            int v = connections[row][1];

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        // number of disconnected components
        unordered_map<int, bool> visited;
        int dis_com = 0;

        for (auto node : adj_list) {

            if (!visited[node.first]) {
                dfs(node.first, visited);
                dis_com++;
            }
        }

        return dis_com-1;
    }
};