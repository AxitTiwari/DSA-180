// https://leetcode.com/submissions/detail/2011798994/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited,
             long long &count) {

        visited[node] = true;
        count++;

        for (int nbr : graph[node]) {

            if (!visited[nbr]) {
                dfs(nbr, graph, visited, count);
            }
        }
    }

public:

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto &e : edges) {

            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<long long> components;
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                long long count = 0;
                dfs(i, graph, visited, count);
                components.push_back(count);
            }
        }

        long long ans = 0;
        long long remaining = n;
        for (long long size : components) {

            ans += size * (remaining - size);

            remaining -= size;
        }

        return ans;
    }
};