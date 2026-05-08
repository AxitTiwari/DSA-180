// https://leetcode.com/problems/maximal-network-rank/submissions/1998201248

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void add_edge(int u, int v, unordered_map<int, list<int>>& graph) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, list<int>> graph;
        for (auto road : roads) {
            add_edge(road[0], road[1], graph);
        }

        int rank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {

                // sum of nbrs
                int node_rank = graph[i].size() + graph[j].size();

                // connected nodes, -> -1
                if(find(graph[j].begin(), graph[j].end(), i) != graph[j].end()) {
                    node_rank--;
                }

                rank = max(rank, node_rank);
            }
        }
        return rank;
    }
};