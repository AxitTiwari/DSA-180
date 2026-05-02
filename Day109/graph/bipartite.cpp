// https://leetcode.com/problems/is-graph-bipartite/submissions/1992984719

#include <bits/stdc++.h>
using namespace std;

class MySolution {
private:
    bool bfs(int node, vector<vector<int>>& graph, unordered_map<int, int>& color) {

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {

            int cur_node = q.front();
            q.pop();

            for (auto nbr : graph[cur_node]) {

                if (color[nbr] == -1) {
                    color[nbr] = 1 - color[cur_node];
                    q.push(nbr);
                }
                else if (color[nbr] == color[cur_node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool is_bipartite(vector<vector<int>>& graph) {

        unordered_map<int, int> color;
        for (int i = 0; i < graph.size(); i++) {
            color[i] = -1;
        }

        for (int i = 0; i < graph.size(); i++) {

            if (color[i] == -1) {

                // if not a bipartite then only immediatly return false
                if (!(bfs(i, graph, color))) {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
private:
    bool solve(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);   // -1 = uncolored
        
        for(int i = 0; i < n; i++) {
            
            if(color[i] != -1) continue;  // already visited
            
            queue<int> q;
            q.push(i);
            color[i] = 0;   // start coloring
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(auto neigh : graph[node]) {
                    
                    if(color[neigh] == -1) {
                        // assign opposite color
                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    }
                    else if(color[neigh] == color[node]) {
                        // same color conflict
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // return solve(graph);

        MySolution obj = MySolution();
        return obj.is_bipartite(graph);
    }
};