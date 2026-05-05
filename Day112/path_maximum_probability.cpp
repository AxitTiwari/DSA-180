// https://leetcode.com/problems/path-with-maximum-probability/submissions/1995651554

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void add_edge(int u, int v, double wt, unordered_map<int, list<pair<int, double>>>& graph) {
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int, list<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            add_edge(u, v, wt, graph);
        }
        priority_queue<pair<double,double>> max_heap; // (prob, node)

        vector<double> probabilitie(n+1, INT_MIN);
        probabilitie[start_node] = 0;

        max_heap.push({1, start_node});

        while (!max_heap.empty()) {

            auto [prob, node] = max_heap.top();
            max_heap.pop();

            if (node == end_node) {

                // cout << node << ": " << end_node << endl;
                return probabilitie[node];
            }

            // realaxation
            for (auto &[nbr, pb] : graph[node]) {

                if (prob * pb > probabilitie[nbr]) {
                    probabilitie[nbr] = prob * pb;

                    // cout << prob << "*" << pb << endl;
                    max_heap.push({probabilitie[nbr], nbr});
                }
            }
        }
        return 0;
    }
};