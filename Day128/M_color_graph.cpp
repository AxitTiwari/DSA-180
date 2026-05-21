// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void add_edge(int u, int v, unordered_map<int, list<int>> &graph) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    bool possible(int node, int col, unordered_map<int, list<int>> &graph, vector<int> &color) {
        
        for (auto nbr : graph[node]) {
            if (color[nbr] == col) {
                return false;
            }
        }
        return true;
    }
    
    bool can_color(int node, int m, unordered_map<int, list<int>> &graph, vector<int> &color) {
            
        if (node == graph.size()) {
            return true;
        }
        
        for (int col = 1; col <= m; col++) {
            if (possible(node, col, graph, color)) {
                color[node] = col;
                
                if (can_color(node+1, m, graph, color)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        
        unordered_map<int, list<int>> graph;
        for (auto e : edges) {
            add_edge(e[0], e[1], graph);
        }
        
        vector<int> color(v+1, 0);
        return can_color(0, m, graph, color);
    }
};