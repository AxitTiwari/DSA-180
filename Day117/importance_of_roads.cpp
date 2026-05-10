// https://leetcode.com/problems/maximum-total-importance-of-roads/submissions/1999856729

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<int>>& graph) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, list<int>> graph;
        for (auto road : roads) {
            add_edge(road[0], road[1], graph);
        }

        vector<int> degree(n, 0);
        for (auto node : graph) {

            for (auto nbr : node.second) {
                degree[nbr]++;
            }
        }

        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < degree.size(); i++) {
            max_heap.push({degree[i], i});
        }

        vector<int> importance(n+1);
        int imp = n;
        while (!max_heap.empty()) {

            pair<int, int> value = max_heap.top();
            max_heap.pop();
            importance[value.second] = imp;
            imp--;
        }

        long long ans = 0;
        unordered_map<int, bool> visited;
        for (auto node : graph) {

            int u = node.first;
            int imp_u = importance[u];

            visited[u] = true;

            for (auto v : node.second) {

                if (!visited[v]) {
                    int imp_v = importance[v];
                    ans += imp_u + imp_v;
                }
            }
        }
        return ans;
    }
};